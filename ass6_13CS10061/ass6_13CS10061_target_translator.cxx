# include "ass6_13CS10061_translator.h"
# include "y.tab.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <iostream>

using namespace std;

void update_offsets(){
  int i,j;
  int off_param = 16, loc_param = 0;
  int state = 0;
  symbolTable *temp;
  for(i = 0; i<= global->curr_length; i++){
      if((global->table[i]).nestedTable){
          temp = (global->table[i]).nestedTable;
          off_param = 16;
          loc_param = 0;
          state = 0;
          for(j = 0;j <= temp->curr_length; j++){
            /* Update offsets for parameters first */
            if(!strcmp((temp->table[j]).name, "retVal")){
              state = 1;
            }
            else{
              if(state == 0){
                (temp->table[j]).offset = off_param;
                off_param += (temp->table[j]).size;
              }
              else{
                loc_param -= (temp->table[j]).size;
                (temp->table[j]).offset = loc_param;
              }
            }
          }
      }
  }
}

int label_number = 0;
void generate_labels(char **s){
  int i,lb;
  quadArrayRow *q;
  for(i = 0;i<next_instr;i++){
    q = (quad_array->quad_Table) + i;
    if(q->op == goto_LT || q->op == goto_LTE || q->op == goto_GT || q->op == goto_GTE || q->op == goto_EQ || q->op == goto_NEQ || q->op == GOTO || q->op == IF_GOTO || q->op == IF_FALSE_GOTO){
      lb = atoi(q->res);
      if(!s[lb]){
           s[lb] = new char[10];
          sprintf(s[lb],".L%d",label_number);
          label_number++;
      }
    }
  }
}

/* generate the list of strings used by the 'prints' function */
void generate_strings(){
  int i;
  if(count_toc>0)
    printf("\t.section\t.rodata\n");
  for(i=0;i<count_toc;i++){
    printf(".LC%d:\n",i);
    printf("\t.string\t%s\n",toc[i]);
  }
  printf("\t.text\n");
}

/* function to update the global varibales and store their offset as -1 to identify them as global and use them by their name */
void update_global_variables(){
    int i,flag = 0;
    symbolTableRow *temp = global->table;
    for(i = 0;i <= global->curr_length;i++){
      if(!((temp[i]).nestedTable)){
          temp[i].offset = -1;
          if(!(temp[i].initial_value)){
            printf("\t.comm\t%s,%d\n",temp[i].name,temp[i].size);
          }
          else{
            /* first obtain initial value */
            int init_val;
            int *dummy;
            char *dummy1;
            if((temp[i].Type)->middle == INT){
              dummy = (int *)(temp[i].initial_value);
              init_val = *dummy;
            }
            else{ // Type is char
              dummy1 = (char *)(temp[i].initial_value);
              init_val = (int)(*dummy1);
            }
            /* Now generate assembly codes */
            printf("\t.globl\t%s\n",temp[i].name);
            if(flag == 0){
              printf("\t.data\n");
              flag = 1;
            }
            printf("\t.type\t%s, @object\n",temp[i].name);
            printf("\t.size\t%s, %d\n",temp[i].name,temp[i].size);
            printf("%s:\n",temp[i].name);
            printf("\t.long\t%d\n",init_val);
          }
      }
    }
}

/* find the size of a given function (necessary to allocate space for the local variables and parameter variables) */

int sizeSymbolTable(symbolTable *t){
  int i,size = 0,state = 0;
  symbolTableRow *temp = t->table;
  for(i=0;i<=t->curr_length;i++){
    if(!strcmp(temp[i].name,"retVal"))
      state = 1;
    else{
      if(state == 1){
        size += temp[i].size;
      }
    }
  }
  return size;
}

/*  updates size of chars to 4 and size of ptrs to 8 */

void update_size(symbolTable *t){  
  int i;
  symbolTableRow *temp = t->table;
  tree_Node_Type *possible;
  for(i = 0;i<=t->curr_length;i++){
    if(!temp[i].nestedTable){
      possible = temp[i].Type;
      while(possible){
        if(possible->middle == PTR || possible->middle == INT)
        {
            if(possible->middle == PTR)
                temp[i].size*=2;
            break;
        }
        if(possible->middle == CHAR){
          temp[i].size *= 4;
          break;
        }
        possible = possible->right;
      }
    }
    else
      update_size(temp[i].nestedTable);
  }
}

/* the translator or the map of each quad->op to a set of assembly instructions */

void translator(){
  int gb_total_off=0;
  int i,size,off;
  char *name;
  quadArrayRow *temp = quad_array->quad_Table;
  for(i = 0;i < next_instr;i++){
    switch((temp[i]).op){
      case Function : size = sizeSymbolTable((temp[i].arg1_loc)->nestedTable);
                      name = strdup(temp[i].arg1);
                      printf("\t.globl\t%s\n",temp[i].arg1);
                      printf("\t.type\t%s, @function\n",temp[i].arg1);
                      printf("%s:\n",temp[i].arg1);
                      /* Function prologue */
                      printf("\tpushq\t%%rbp\n");
                      printf("\tmovq\t%%rsp, %%rbp\n");
                      printf("\tsubq\t$%d, %%rsp\n",size);
                      break;

      case RETURN_EXP : off = (temp[i].arg1_loc)->offset;
                        if(s[i])
                          printf("%s:\n",s[i]);
                        if(off == -1)
                          printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                        else
                          printf("\tmovl\t%d(%%rbp), %%eax\n",off);
                        printf("\tleave\n");
                        printf("\tret\n");
                        printf("\t.size\t%s, .-%s\n",name,name);
                        break;
      case RETURN :     if(s[i])
                          printf("%s:\n",s[i]);
                        printf("\tnop\n");
                        printf("\tleave\n");
                        printf("\tret\n");
                        printf("\t.size\t%s, .-%s\n",name,name);
                        break;
      case  PLUS :      off = (temp[i].arg1_loc)->offset;
                        if(s[i])
                          printf("%s:\n",s[i]);
                        if(off == -1)
                          printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                        else
                          printf("\tmovl\t%d(%%rbp), %%eax\n",off);
                        off = (temp[i].arg2_loc)->offset;
                        if(off == -1)
                          printf("\tmovl\t%s(%%rip), %%edx\n",(temp[i].arg2_loc)->name);
                        else
                          printf("\tmovl\t%d(%%rbp), %%edx\n",off);
                        printf("\taddl\t%%edx, %%eax\n");
                        off = (temp[i].res_loc)->offset;
                        if(off == -1)
                          printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                        else
                          printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                        break;
      case  MINUS :     off = (temp[i].arg1_loc)->offset;
                        if(s[i])
                          printf("%s:\n",s[i]);
                        if(off == -1)
                          printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                        else
                          printf("\tmovl\t%d(%%rbp), %%eax\n",off);
                        off = (temp[i].arg2_loc)->offset;
                        if(off == -1)
                          printf("\tmovl\t%s(%%rip), %%edx\n",(temp[i].arg2_loc)->name);
                        else
                          printf("\tmovl\t%d(%%rbp), %%edx\n",off);
                        printf("\tsubl\t%%edx, %%eax\n");
                        off = (temp[i].res_loc)->offset;
                        if(off == -1)
                          printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                        else
                          printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                        break;
      case  INTO  :     off = (temp[i].arg1_loc)->offset;
                        if(s[i])
                          printf("%s:\n",s[i]);
                        if(off == -1)
                          printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                        else
                          printf("\tmovl\t%d(%%rbp), %%eax\n",off);
                        off = (temp[i].arg2_loc)->offset;
                        if(off == -1)
                          printf("\timull\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                        else
                          printf("\timull\t%d(%%rbp), %%eax\n",off);
                        off = (temp[i].res_loc)->offset;
                        if(off == -1)
                          printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                        else
                          printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                        break;
      case  DIV   :     off = (temp[i].arg1_loc)->offset;
                        if(s[i])
                          printf("%s:\n",s[i]);
                        if(off == -1)
                          printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                        else
                          printf("\tmovl\t%d(%%rbp), %%eax\n",off);
                        printf("\tcltd\n");
                        off = (temp[i].arg2_loc)->offset;
                        if(off == -1)
                          printf("\tidivl\t%s(%%rip)\n",(temp[i].arg2_loc)->name);
                        else
                          printf("\tidivl\t%d(%%rbp)\n",off);
                        off = (temp[i].res_loc)->offset;
                        if(off == -1)
                          printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                        else
                          printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                        break;
      case  PERCENT :   off = (temp[i].arg1_loc)->offset;
                        if(s[i])
                          printf("%s:\n",s[i]);
                        if(off == -1)
                          printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                        else
                          printf("\tmovl\t%d(%%rbp), %%eax\n",off);
                        printf("\tcltd\n");
                        off = (temp[i].arg2_loc)->offset;
                        if(off == -1)
                          printf("\tidivl\t%s(%%rip)\n",(temp[i].arg2_loc)->name);
                        else
                          printf("\tidivl\t%d(%%rbp)\n",off);
                        off = (temp[i].res_loc)->offset;
                        if(off == -1)
                          printf("\tmovl\t%%edx, %s(%%rip)\n",(temp[i].res_loc)->name);
                        else
                          printf("\tmovl\t%%edx, %d(%%rbp)\n",off);
                        break;

      case  LT      : off = (temp[i].arg1_loc)->offset;
                      if(s[i])
                          printf("%s:\n",s[i]);
                      if(off == -1)
                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                      else
                        printf("\tmovl\t%d(%%rbp), %%eax\n",off);  
                      off = (temp[i].arg2_loc)->offset;
                      if(off == -1)
                        printf("\tcmpl\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                      else
                        printf("\tcmpl\t%d(%%rbp), %%eax\n",off);
                      printf("\tsetl\t%%al\n");
                      printf("\tmovzbl\t%%al, %%eax\n");
                      off = (temp[i].res_loc)->offset;
                      if(off == -1)
                        printf("\tmovl\t%%eax, %s\n",(temp[i].res_loc)->name);
                      else
                        printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                      break;
      case  LTE     : off = (temp[i].arg1_loc)->offset;
                      if(s[i])
                          printf("%s:\n",s[i]);
                      if(off == -1)
                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                      else
                        printf("\tmovl\t%d(%%rbp), %%eax\n",off);  
                      off = (temp[i].arg2_loc)->offset;
                      if(off == -1)
                        printf("\tcmpl\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                      else
                        printf("\tcmpl\t%d(%%rbp), %%eax\n",off);
                      printf("\tsetle\t%%al\n");
                      printf("\tmovzbl\t%%al, %%eax\n");
                      off = (temp[i].res_loc)->offset;
                      if(off == -1)
                        printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                      else
                        printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                      break;
      case  GT      : off = (temp[i].arg1_loc)->offset;
                      if(s[i])
                          printf("%s:\n",s[i]);
                      if(off == -1)
                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                      else
                        printf("\tmovl\t%d(%%rbp), %%eax\n",off);  
                      off = (temp[i].arg2_loc)->offset;
                      if(off == -1)
                        printf("\tcmpl\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                      else
                        printf("\tcmpl\t%d(%%rbp), %%eax\n",off);
                      printf("\tsetg\t%%al\n");
                      printf("\tmovzbl\t%%al, %%eax\n");
                      off = (temp[i].res_loc)->offset;
                      if(off == -1)
                        printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                      else
                        printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                      break;
      case  GTE      :off = (temp[i].arg1_loc)->offset;
                      if(s[i])
                          printf("%s:\n",s[i]);
                      if(off == -1)
                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                      else
                        printf("\tmovl\t%d(%%rbp), %%eax\n",off);  
                      off = (temp[i].arg2_loc)->offset;
                      if(off == -1)
                        printf("\tcmpl\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                      else
                        printf("\tcmpl\t%d(%%rbp), %%eax\n",off);
                      printf("\tsetge\t%%al\n");
                      printf("\tmovzbl\t%%al, %%eax\n");
                      off = (temp[i].res_loc)->offset;
                      if(off == -1)
                        printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                      else
                        printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                      break;
      case  EQ      : off = (temp[i].arg1_loc)->offset;
                      if(s[i])
                          printf("%s:\n",s[i]);
                      if(off == -1)
                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                      else
                        printf("\tmovl\t%d(%%rbp), %%eax\n",off);  
                      off = (temp[i].arg2_loc)->offset;
                      if(off == -1)
                        printf("\tcmpl\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                      else
                        printf("\tcmpl\t%d(%%rbp), %%eax\n",off);
                      printf("\tsete\t%%al\n");
                      printf("\tmovzbl\t%%al, %%eax\n");
                      off = (temp[i].res_loc)->offset;
                      if(off == -1)
                        printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                      else
                        printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                      break;
      case  NEQ      : off = (temp[i].arg1_loc)->offset;
                      if(s[i])
                          printf("%s:\n",s[i]);
                      if(off == -1)
                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                      else
                        printf("\tmovl\t%d(%%rbp), %%eax\n",off);  
                      off = (temp[i].arg2_loc)->offset;
                      if(off == -1)
                        printf("\tcmpl\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                      else
                        printf("\tcmpl\t%d(%%rbp), %%eax\n",off);
                      printf("\tsetne\t%%al\n");
                      printf("\tmovzbl\t%%al, %%eax\n");
                      off = (temp[i].res_loc)->offset;
                      if(off == -1)
                        printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                      else
                        printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                      break;
        case  goto_LT :off = (temp[i].arg1_loc)->offset;
                      if(s[i])
                        printf("%s:\n",s[i]);                      
                      if(off == -1)
                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                      else
                        printf("\tmovl\t%d(%%rbp), %%eax\n",off);  
                      off = (temp[i].arg2_loc)->offset;
                      if(off == -1)
                        printf("\tcmpl\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                      else
                        printf("\tcmpl\t%d(%%rbp), %%eax\n",off);
                      printf("\tjl\t%s\n",s[atoi(temp[i].res)]);
                      break;
        case  goto_GT :off = (temp[i].arg1_loc)->offset;
                      if(s[i])
                        printf("%s:\n",s[i]);                      
                      if(off == -1)
                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                      else
                        printf("\tmovl\t%d(%%rbp), %%eax\n",off);  
                      off = (temp[i].arg2_loc)->offset;
                      if(off == -1)
                        printf("\tcmpl\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                      else
                        printf("\tcmpl\t%d(%%rbp), %%eax\n",off);
                      printf("\tjg\t%s\n",s[atoi(temp[i].res)]);
                      break;
        case  goto_GTE :off = (temp[i].arg1_loc)->offset;
                      if(s[i])
                        printf("%s:\n",s[i]);                      
                      if(off == -1)
                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                      else
                        printf("\tmovl\t%d(%%rbp), %%eax\n",off);  
                      off = (temp[i].arg2_loc)->offset;
                      if(off == -1)
                        printf("\tcmpl\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                      else
                        printf("\tcmpl\t%d(%%rbp), %%eax\n",off);
                      printf("\tjge\t%s\n",s[atoi(temp[i].res)]);
                      break;
        case  goto_LTE:off = (temp[i].arg1_loc)->offset;
                      if(s[i])
                        printf("%s:\n",s[i]);                      
                      if(off == -1)
                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                      else
                        printf("\tmovl\t%d(%%rbp), %%eax\n",off);  
                      off = (temp[i].arg2_loc)->offset;
                      if(off == -1)
                        printf("\tcmpl\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                      else
                        printf("\tcmpl\t%d(%%rbp), %%eax\n",off);
                      printf("\tjle\t%s\n",s[atoi(temp[i].res)]);
                      break;
        case  goto_EQ : off = (temp[i].arg1_loc)->offset;
                      if(s[i])
                        printf("%s:\n",s[i]);                      
                      if(off == -1)
                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                      else
                        printf("\tmovl\t%d(%%rbp), %%eax\n",off);  
                      off = (temp[i].arg2_loc)->offset;
                      if(off == -1)
                        printf("\tcmpl\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                      else
                        printf("\tcmpl\t%d(%%rbp), %%eax\n",off);
                      printf("\tje\t%s\n",s[atoi(temp[i].res)]);
                      break;
        case  goto_NEQ : off = (temp[i].arg1_loc)->offset;
                      if(s[i])
                        printf("%s:\n",s[i]);                      
                      if(off == -1)
                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                      else
                        printf("\tmovl\t%d(%%rbp), %%eax\n",off);  
                      off = (temp[i].arg2_loc)->offset;
                      if(off == -1)
                        printf("\tcmpl\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                      else
                        printf("\tcmpl\t%d(%%rbp), %%eax\n",off);
                      printf("\tjne\t%s\n",s[atoi(temp[i].res)]);
                      break;
        case  GOTO   :if(s[i])
                        printf("%s:\n",s[i]);
                      printf("\tjmp\t%s\n",s[atoi(temp[i].res)]);
                      break;
        case  IF_GOTO :if(s[i])
                        printf("%s:\n",s[i]);
                       off = (temp[i].arg1_loc)->offset;
                       if(off == -1)
                        printf("\tcmpl\t$0, %s(%%rip)\n",(temp[i].arg1_loc)->name);
                       else
                        printf("\tcmpl\t$0, %d(%%rbp)\n",off);
                      printf("\tjne\t%s\n",s[atoi(temp[i].res)]);
                      break;
        case  IF_FALSE_GOTO :if(s[i])
                        printf("%s:\n",s[i]);
                       off = (temp[i].arg1_loc)->offset;
                       if(off == -1)
                        printf("\tcmpl\t$0, %s(%%rip)\n",(temp[i].arg1_loc)->name);
                       else
                        printf("\tcmpl\t$0, %d(%%rbp)\n",off);
                      printf("\tje\t%s\n",s[atoi(temp[i].res)]);
                      break;
        case  U_PLUS  :if(s[i])
                        printf("%s:\n",s[i]);
                       off = (temp[i].arg1_loc)->offset;
                       if(off == -1)
                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                       else
                        printf("\tmovl\t%d(%%rbp), %%eax\n",off); 
                      off = (temp[i].res_loc)->offset;
                      if(off == -1)
                        printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                      else
                        printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                      break;
        case  U_MINUS  :if(s[i])
                          printf("%s:\n",s[i]);
                       off = (temp[i].arg1_loc)->offset;
                       if(off == -1)
                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                       else
                        printf("\tmovl\t%d(%%rbp), %%eax\n",off);
                      printf("\tnegl\t%%eax\n"); 
                      off = (temp[i].res_loc)->offset;
                      if(off == -1)
                        printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                      else
                        printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                      break;
        case  U_NEGATION :if(s[i])
                            printf("%s:\n",s[i]);
                          off = (temp[i].arg1_loc)->offset;
                          if(off == -1)
                            printf("\tcmpl\t$0, %s(%%rip)\n",(temp[i].arg1_loc)->name);
                          else
                            printf("\tcmpl\t$0, %d(%%rbp)\n",off);
                          printf("\tsete\t%%al\n");
                          printf("\tmovzbl\t%%al, %%eax\n");
                          off = (temp[i].res_loc)->offset;
                          if(off == -1)
                            printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                          else
                            printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                          break;
        case  U_ADDR     : if(s[i])
                            printf("%s:\n",s[i]);
                           off = (temp[i].arg1_loc)->offset;
                           if(off == -1)
                            printf("\tleaq\t%s(%%rip), %%rax\n",(temp[i].arg1_loc)->name);
                           else
                            printf("\tleaq\t%d(%%rbp), %%rax\n",off);
                           off = (temp[i].res_loc)->offset;
                           if(off == -1)
                            printf("\tmovq\t%%rax, %s(%%rip)\n",(temp[i].res_loc)->name);
                           else
                            printf("\tmovq\t%%rax, %d(%%rbp)\n",off);
                           break;
        case  U_STAR     : if(s[i])
                            printf("%s:\n",s[i]);
                           off = (temp[i].arg1_loc)->offset;
                           if(off == -1)
                            printf("\tmovq\t%s(%%rip), %%rax\n",(temp[i].arg1_loc)->name);
                           else
                            printf("\tmovq\t%d(%%rbp), %%rax\n",off);
                           printf("\tmovl\t(%%rax), %%eax\n");
                           off = (temp[i].res_loc)->offset;
                           if(off == -1)
                            printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                           else
                            printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                           break;
        case  ASSIGN     : if(s[i])
                            printf("%s:\n",s[i]);
                           if(!(temp[i].arg1_loc))
                             printf("\tmovl\t$%s, %%eax\n",temp[i].arg1);
                           else{
                             if((temp[i].arg1_loc)->Type->middle == ARRAY){
                              off = (temp[i].arg1_loc)->offset;
                              if(off == -1)
                                printf("\tleaq\t%s(%%rip), %%rax\n",(temp[i].arg1_loc)->name);
                              else
                                printf("\tleaq\t%d(%%rbp), %%rax\n",off);
                             }
                             else{
                                off = (temp[i].arg1_loc)->offset;
                                if((temp[i].arg1_loc)->Type->middle == PTR){
                                 if(off == -1)
                                  printf("\tmovq\t%s(%%rip), %%rax\n",(temp[i].arg1_loc)->name);
                                 else
                                  printf("\tmovq\t%d(%%rbp), %%rax\n",off);
                                }
                                else
                                {
                                    if(off == -1)
                                        printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg1_loc)->name);
                                    else
                                        printf("\tmovl\t%d(%%rbp), %%eax\n",off);
                                }
                                 
                             }
                           }
                           off = (temp[i].res_loc)->offset;
                           if ((temp[i].res_loc)->Type->middle == ARRAY || (temp[i].res_loc)->Type->middle == PTR){
                               if(off == -1)
                                    printf("\tmovq\t%%rax, %s(%%rip)\n",(temp[i].res_loc)->name);
                               else
                                    printf("\tmovq\t%%rax, %d(%%rbp)\n",off);
                           }
                           else
                           {
                               if(off == -1)
                                   printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                               else
                                   printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                           }
                           break;
        case  LEFT_STAR  : if(s[i])
                            printf("%s:\n",s[i]);
                           off = (temp[i].res_loc)->offset;
                           if(off == -1)
                            printf("\tmovq\t%s(%%rip), %%rax\n",(temp[i].res_loc)->name);
                           else
                            printf("\tmovq\t%d(%%rbp), %%rax\n",off);
                           off = (temp[i].arg1_loc)->offset;
                           if(off == -1)
                            printf("\tmovl\t%s(%%rip), %%edx\n",(temp[i].arg1_loc)->name);
                           else
                            printf("\tmovl\t%d(%%rbp), %%edx\n",off);
                           printf("\tmovl\t%%edx, (%%rax)\n");
                           break;  
        case  EQ_BRACKET  :if(s[i])
                            printf("%s:\n",s[i]);
                           off = (temp[i].arg2_loc)->offset;
                           if(off == -1)
                            printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                           else
                            printf("\tmovl\t%d(%%rbp), %%eax\n",off);
                           off = (temp[i].arg1_loc)->offset;
                           if((temp[i].arg1_loc)->Type->middle == PTR){
                              if(off == -1)
                                printf("\tmovq\t%s(%%rip), %%rdx\n",(temp[i].arg1_loc)->name);
                              else
                                printf("\tmovq\t%d(%%rbp), %%rdx\n",off);
                            }
                            else{
                              if(off == -1)
                               printf("\tleaq\t%s(%%rip), %%rdx\n",(temp[i].arg1_loc)->name);
                              else{
                                printf("\tleaq\t%d(%%rbp), %%rdx\n",off);
                              }
                            }
                           printf("\taddq\t%%rdx, %%rax\n");
                           printf("\tmovl\t(%%rax), %%eax\n");
                           off = (temp[i].res_loc)->offset;
                           if(off == -1)
                            printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                           else
                            printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                          break;
        case  BRACKET_EQ  :if(s[i])
                            printf("%s:\n",s[i]);
                           off = (temp[i].arg2_loc)->offset;
                           if(off == -1)
                            printf("\tmovl\t%s(%%rip), %%eax\n",(temp[i].arg2_loc)->name);
                           else
                            printf("\tmovl\t%d(%%rbp), %%eax\n",off);
                           off = (temp[i].arg1_loc)->offset;
                           if((temp[i].arg1_loc)->Type->middle == PTR){
                              if(off == -1)
                                printf("\tmovq\t%s(%%rip), %%rdx\n",(temp[i].arg1_loc)->name);
                              else
                                printf("\tmovq\t%d(%%rbp), %%rdx\n",off);
                            }
                            else{
                              if(off == -1)
                               printf("\tleaq\t%s(%%rip), %%rdx\n",(temp[i].arg1_loc)->name);
                              else{
                                printf("\tleaq\t%d(%%rbp), %%rdx\n",off);
                              }
                            }
                           printf("\taddq\t%%rdx, %%rax\n");
                           off = (temp[i].res_loc)->offset;
                           if(off == -1)
                            printf("\tmovl\t%s(%%rip), %%edx\n",(temp[i].res_loc)->name);
                           else
                            printf("\tmovl\t%d(%%rbp), %%edx\n",off);
                           printf("\tmovl\t%%edx, (%%rax)\n");
                           break;
          case  call      :if(s[i])
                            printf("%s:\n",s[i]);
                          printf("\tcall\t%s\n",temp[i].arg1);
                          printf ("\taddq\t$%d, %%rsp\n",gb_total_off);
                          off = (temp[i].res_loc)->offset;
                           if(off == -1)
                            printf("\tmovl\t%%eax, %s(%%rip)\n",(temp[i].res_loc)->name);
                           else
                            printf("\tmovl\t%%eax, %d(%%rbp)\n",off);
                           break;
          case  call_void  :if(s[i])
                              printf("%s:\n",s[i]);
                              printf("\tcall\t%s\n",temp[i].arg1);
                            break;
          case  PARAM       :if(s[i])
                              printf("%s:\n",s[i]);
                            int j;
                            int total_off=0;
                            for(j=i;;j++){
                              if(temp[j].op == call || temp[j].op == call_void)
                              {
                                break;
                              }
                              else
                              {
                                  if ((temp[j].arg1_loc)->size==-1)
                                      total_off+=4;
                                  else if ((temp[j].arg1_loc)->Type->middle == ARRAY)
                                      total_off+= 8;
                                  else
                                      total_off+= (temp[j].arg1_loc)->size;
                              }
                                
                            }
                            gb_total_off = total_off;
                              j--;
                              int t = j;
                              printf ("\tsubq\t$%d, %%rsp\n",total_off);
                              while(j>=i){
                                off = (temp[j].arg1_loc)->offset;
                                if((temp[j].arg1_loc)->size == -1){
                                  printf("\tmovl\t$%s, %%eax\n",temp[j].arg1);
                                  printf("\tmovl\t%%eax, %d(%%rsp)\n",total_off-4);
                                    total_off-=4;
                                }
                                else if((temp[j].arg1_loc)->Type->middle == ARRAY){
                                  if(off == -1)
                                    printf("\tleaq\t%s, %%rax\n",(temp[j].arg1_loc)->name);
                                  else
                                    printf("\tleaq\t%d(%%rbp), %%rax\n",off);
                                    printf("\tmovq\t%%rax, %d(%%rsp)\n",total_off-8);
                                    total_off-= 8;
                                }
                                else if ((temp[j].arg1_loc)->size== 8){
                                    if (off == -1)
                                        printf("\tmovq\t%s, %%rax\n",(temp[j].arg1_loc)->name);
                                    else
                                        printf("\tmovq\t%d(%%rbp), %%rax\n",off);
                                    printf("\tmovq\t%%rax, %d(%%rsp)\n",total_off-((temp[j].arg1_loc)->size));
                                    total_off-= (temp[j].arg1_loc)->size;
                                }
                                else{
                                  if(off == -1)
                                    printf("\tmovl\t%s(%%rip), %%eax\n",(temp[j].arg1_loc)->name);
                                  else
                                    printf("\tmovl\t%d(%%rbp), %%eax\n",off);
                                  printf("\tmovl\t%%eax, %d(%%rsp)\n",total_off-((temp[j].arg1_loc)->size));
                                  total_off-= (temp[j].arg1_loc)->size;
                                }
                                
                                
                                j--;
                              }
                            j++;
                            while(j>=i){
                                off = (temp[j].arg1_loc)->offset;
                                if((temp[j].arg1_loc)->size == -1)
                                    printf("\tmovl\t$%s, %%edi\n",temp[j].arg1);
                                else if((temp[j].arg1_loc)->Type->middle == ARRAY){
                                    if(off == -1)
                                        printf("\tleaq\t%s, %%rdi\n",(temp[j].arg1_loc)->name);
                                    else
                                        printf("\tleaq\t%d(%%rbp), %%rdi\n",off);
                                }
                                else if ((temp[j].arg1_loc)->size== 8){
                                    if (off == -1)
                                        printf("\tmovq\t%s, %%rdi\n",(temp[j].arg1_loc)->name);
                                    else
                                        printf("\tmovq\t%d(%%rbp), %%rdi\n",off);
                                }
                                else{
                                    if(off == -1)
                                        printf("\tmovl\t%s(%%rip), %%edi\n",(temp[j].arg1_loc)->name);
                                    else
                                        printf("\tmovl\t%d(%%rbp), %%edi\n",off);
                                }
                                j--;
                            }
                            i = t;
                            break;

    }
  }
}

/* The main function */
int main(){
  global = create_Symbol_Table();
  current = global;
  quad_array = new quadArray(1000);
  int i;
  toc = new char*[MAX_SIZE];
  for(i = 0; i<MAX_SIZE;i++)
    toc[i] = 0;
  s = new char*[MAX_SIZE];
  for(i = 0; i<MAX_SIZE;i++)
    s[i] = 0;
  int x = yyparse();
  update_size(global);
  /*printf("Global Symbol Table : \n");
  global->print_table();
  int j;
  for(i=0;i<=global->curr_length;i++){
    if((global->table[i]).nestedTable){
      printf("%s Symbol table :  \n",(global->table[i]).name);
      ((global->table[i]).nestedTable)->print_table();
    }
  }*/
  //quad_array->print_quadArray();
  update_offsets();
  //printf("**** Now printing update symbol tables *****\n");
  //printf("Global Symbol Table : \n");
  //global->print_table();
  //for(i=0;i<=global->curr_length;i++){
   // if((global->table[i]).nestedTable){
    //  printf("%s Symbol table :  \n",(global->table[i]).name);
    //  ((global->table[i]).nestedTable)->print_table();
   // }
  //}
  generate_labels(s);
  /*for(i = 0;i < next_instr;i++){
    if(!s[i])
      printf("%d\t...\n",i);
    else
      printf("%d\t%s\n",i,s[i]);
  }*/
  generate_strings();
  update_global_variables();
  translator();
  return 0;
}
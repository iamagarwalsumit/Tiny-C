a.out:	y.tab.o lex.yy.o ass4_13CS10061_main.o 
	gcc ass4_13CS10061_main.o lex.yy.o y.tab.o -lfl
lex.yy.c:	ass4_13CS10061.l
	flex ass4_13CS10061.l
y.tab.c:	ass4_13CS10061.y
	yacc -dtv ass4_13CS10061.y
ass4_13CS10061_main.o:	ass4_13CS10061_main.c
	gcc -c ass4_13CS10061_main.c
lex.yy.o:	lex.yy.c
	gcc -c lex.yy.c
y.tab.o:	y.tab.c
	gcc -c y.tab.c

clean:
	rm lex.yy.c y.tab.h y.output y.tab.c lex.yy.o y.tab.o ass4_13CS10061_main.o a.out

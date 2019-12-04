a.out:	y.tab.o lex.yy.o ass3_13CS10061.o 
	gcc ass3_13CS10061.o lex.yy.o y.tab.o -lfl
lex.yy.c:	ass3_13CS10061.l
	flex ass3_13CS10061.l
y.tab.c:	ass3_13CS10061.y
	yacc -dtv ass3_13CS10061.y
ass3_13CS10061.o:	ass3_13CS10061.c
	gcc -c ass3_13CS10061.c
lex.yy.o:	lex.yy.c
	gcc -c lex.yy.c
y.tab.o:	y.tab.c
	gcc -c y.tab.c   

clean:
	rm lex.yy.c y.tab.h y.output y.tab.c lex.yy.o y.tab.o ass3_13CS10061.o a.out




tinyC: lex.yy.o y.tab.o ass6_13CS10061_translator.o ass6_13CS10061_target_translator.o 
	g++ lex.yy.o y.tab.o ass6_13CS10061_translator.o ass6_13CS10061_target_translator.o -lfl -o tinyC


y.tab.o:	y.tab.c
	g++ -c y.tab.c

lex.yy.o:	lex.yy.c
	g++ -c lex.yy.c

lex.yy.c:	ass6_13CS10061.l y.tab.c
	flex ass6_13CS10061.l

y.tab.c:	ass6_13CS10061.y
	yacc -dtv -Wother ass6_13CS10061.y

ass6_13CS10061_translator.o: ass6_13CS10061_translator.h ass6_13CS10061_translator.cxx
	g++ -c ass6_13CS10061_translator.cxx

ass6_13CS10061_target_translator.o: ass6_13CS10061_target_translator.cxx
	g++ -c ass6_13CS10061_target_translator.cxx 

clean:
	rm tinyC y.tab.o lex.yy.o lex.yy.c y.tab.c y.tab.h y.output ass6_13CS10061_translator.o ass6_13CS10061_target_translator.o



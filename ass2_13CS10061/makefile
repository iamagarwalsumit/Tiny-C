a.out: main_ass2.o libass2_13CS10061.a
	c++ main_ass2.o -L. -lass2_13CS10061 

main_ass2.o:	main_ass2.c++ my_stdio.h
	c++ -Wall -c main_ass2.c++

libass2_13CS10061.a:	ass2_13CS10061.o
		ar -rcs libass2_13CS10061.a ass2_13CS10061.o

ass2_13CS10061.o:	ass2_13CS10061.c++ my_stdio.h
	cc -Wall -c ass2_13CS10061.c++
clean:
	rm a.out main_ass2.o libass2_13CS10061.a ass2_13CS10061.o

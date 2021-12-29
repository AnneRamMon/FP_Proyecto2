calculadora: main.o pol.o
	gcc -o calculadora main.o pol.o

main.o : main.c pol.h
	gcc -c main.c

pol.o : pol.c pol.h
	gcc -c pol.c


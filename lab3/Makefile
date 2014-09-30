all:
	gcc -c linktable.c -o linktable.o
	gcc -c menu.c -o menu.o
	gcc -c testinterface.c -o testinterface.o
	gcc linktable.o menu.o testinterface.o -o test

clean:
	rm -rf *.o test


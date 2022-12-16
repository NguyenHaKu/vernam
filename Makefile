vernam : vernam.o
	gcc -Wall -ansi -o vernam vernam.o

vernam.o : vernam.c
	gcc -c vernam.c

clean :
	rm -f *.o
	
run : vernam
	./vernam -k

all: iaxpy.c fdot.c dgemm.c clean make run

make:
	gcc -Wall iaxpy.c -o iaxpy
	gcc -Wall fdot.c -o fdot
	gcc -Wall dgemm.c -o dgemm

clean:
	rm -f *.o

run:
	for i in {1..3}; do time ./iaxpy; done;
	for i in {1..3}; do time ./fdot; done;
	for i in {1..3}; do time ./dgemm; done;


CC=gcc
CFLAGS=-Wall -o

all: test

test: driver.o
	$(CC) $(CFLAGS) test -O2 driver.o

driver.o: driver.c
	$(CC) -c driver.c

clean:
	rm -rf *o test
	
run:
	./test 10000 16
	
tarball:
	tar -czvf sitar.tar.gz driver.c Makefile README.txt Report.txt

# c compiler
CC=gcc
# c flags to always include
CFLAGS=-Wall -o
# <arraySize> <maxStepSize> <maxMBSize>
ARGS=10000 33 64

all: test

test: driver.o
	$(CC) $(CFLAGS) test -O2 driver.o

driver.o: driver.c
	$(CC) -c driver.c

clean:
	rm -rf *o test
	
run:
	./test $(ARGS)
	
tarball:
	tar -czvf sitar.tar.gz driver.c Makefile README.txt blockReport.txt cacheReport.txt
	
blockReport:
	less blockReport.txt

cacheReport:
	less cacheReport.txt
// driver class
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//To compile program...
//	gcc -Wall -o test driver.c
//To run program...
//	./test <int arg1>



struct timespec start, stop;
double elapsed;
int step = 8;

int main(int argc, char** argv) {
	if (argc != 2){
		printf("Usage: ./test <arraySize>\n");
		return 1;
	}
    	else {
	    	long aSize = atoi(argv[1]);
	    	printf("aSize = %lu\n", aSize);
	    	int n[aSize];
	    	
	    	// loop for main mem access
	    	for (int i = 1; i < step; i++) {
	   		//take time here
	   		clock_gettime(CLOCK_REALTIME, &start);
	    		for (int j = 0; j < aSize; j++) {
	    		}
	    		//take time here
	   		clock_gettime(CLOCK_REALTIME, &stop);
	    	}
	    	elapsed = stop.tv_sec - start.tv_sec;
	    	elapsed += (stop.tv_nsec - start.tv_nsec) / 1000000000.0;
		printf("Access time %.1fms\n", elapsed * 1000);   
	}
	
    	return 0;

}

// cache block size function

// cache size function

// main memory access time function

// cache memory access time function

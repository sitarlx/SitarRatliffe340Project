// driver class
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//To compile program...
//	gcc -Wall -o test driver.c
//To run program...
//	./test <int arg1> <int arg2>

int main(int argc, char** argv) {
	
	// check correct num args
	if (argc != 3){
		printf("Usage: ./test <arraySize> <stepSize>\n");
		return 1;
	}
    else {
		FILE *fp = fopen("Report.txt", "w");
	    long aSize = atol(argv[1]);
	    long max_step = atol(argv[2]);
	    printf("aSize = %lu\n", aSize);
	    	
	    struct timespec start, stop;
	    long x;
	    double elapsed;
			

	    // loop for main mem access
	    for (long step = 1; step <= max_step; step++) {
			x = 0;
	    	long bSize = aSize * step;
	    	long *n = (long*)malloc(bSize*sizeof(long));
	    		
			//populate array
	    	for (long t = 0; t < bSize; t++) {
	    		n[t] = rand();
	    	}
			// take time here
			clock_gettime(CLOCK_MONOTONIC, &start);
	    	for (long j = 0; j < bSize; j+=step) {
			x = x + n[j];
	    	}
	    		
	    	// take time here
			clock_gettime(CLOCK_MONOTONIC, &stop);
			elapsed = stop.tv_nsec - start.tv_nsec;
			elapsed += (stop.tv_sec - start.tv_sec) * 1000000000.0;
			fprintf(fp, "Mean access time for step = %ld is %.1lfns. With value %ld\n", step, elapsed/aSize, x);
			free(n);
	    }
		fclose(fp);	   
	}
    return 0;
}

// cache block size function

// cache size function

// main memory access time function

// cache memory access time function

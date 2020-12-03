// Logan Sitar and Ryan Ratliffe

// driver class
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//To compile and run program using Makefile...
//	open terminal
//	cd to directoryName
//	make all			"compiles the code"
//	make run			"runs the code"
//	make clean			"removes unecessary files"

long max_its = 10000;
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
		double m[max_step];
		struct timespec start, stop;
	    	long x;
	  	double elapsed;
	  	  
		double sum_x = 0;	
		printf("size of long = %ld\n", sizeof(long));
	  	 // loop for main mem access
	   	 for (long step = 1; step <= max_step; step++) {
	    		long bSize = aSize * step;
			//populate array
	    		m[step-1] = 0;
	    		
			for (long k = 0; k < max_its; k++) {
				long *n = (long*)malloc(bSize*sizeof(long));
				x = 0;
				//for (long t = 0; t < bSize; t++) {
	    				//n[t] = rand();
	    			//}
	    			
				// take time here
		    		clock_gettime(CLOCK_MONOTONIC, &start);
		    		for (long j = 0; j < bSize; j+=step) {	
					x = x + n[j];	
		    		}
		    		// take time here
				clock_gettime(CLOCK_MONOTONIC, &stop);
				elapsed = stop.tv_nsec - start.tv_nsec;
				elapsed += (stop.tv_sec - start.tv_sec) * 1000000000.0;
				m[step - 1] += (elapsed/aSize);
	    			
				sum_x +=x;
				free(n);
			} //end of k loop
			
	  	} // end of step loop
	  	for(long z = 1;z<max_step;z++){
	  		m[z-1] = m[z-1]/max_its;
	  		fprintf(fp, "Mean access time for step = %ld bytes is %.1lfns. \n", z*sizeof(long), m[z-1]);
	  	}
		fclose(fp);	  
		printf("this is the sum of x: %lf", sum_x);
	}
    	return 0;
}

// cache block size function

// cache size function

// main memory access time function

// cache memory access time function

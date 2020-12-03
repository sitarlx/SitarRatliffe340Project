// driver class
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//To compile program...
//	gcc -Wall -o test driver.c
//To run program...
//	./test <int arg1> <int arg2> <int arg3>
long max_its = 10000;
int byte = 1024;
int main(int argc, char** argv){
	// check correct num args
	if (argc != 4){
		printf("Usage: ./test <arraySize> <stepSize>\n");
		return 1;
	}
	else {
	long aSize = atol(argv[1]);
	long max_step = atol(argv[2]);
	blockSize_accessTime(aSize, max_step);
	int max_MB = atol(argv[3]);
	cacheSize(max_MB);
	return 0;
	}
}

int blockSize_accessTime(long aSize, long max_step) {
	FILE *fp = fopen("blockReport.txt", "w");
	double m[max_step];
	struct timespec start, stop;
    	long x;
  	double elapsed;	  
	double sum_x = 0;	
  	// loop for main mem access
   	for (long step = 1; step <= max_step; step++) {
    		long bSize = aSize * step;
		//populate array
    		m[step-1] = 0;
		for (long k = 0; k < max_its; k++) {
			long *n = (long*)malloc(bSize*sizeof(long));
			x = 0;
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
  	
  	//outputs results
  	for(long z = 1;z<max_step;z++){
  		m[z-1] = m[z-1]/max_its;
  		fprintf(fp, "Mean access time for step = %ld bytes is %.1lfns. \n", z*sizeof(long), m[z-1]);
  	}
	fclose(fp);
	return 0;
}

int cacheSize(int max_MB) {
	//CACHE SIZE PART
	FILE *fp2 = fopen("cacheReport.txt", "w");
	int i;
	int j;
	struct timespec beg, end;
	for(j = 1; j<max_MB;j++){
		int jumps = j * byte * byte;
	    	int a[byte * byte];
	    	int len = (byte * byte) - 1;
	    	double elapsed;
	    	clock_gettime(CLOCK_MONOTONIC, &beg);
	    	for (i = 0; i < jumps; i++) {
	       	a[(i * 16) & len]++;
	    	}
	    	clock_gettime(CLOCK_MONOTONIC, &end);
	    	elapsed = end.tv_nsec - beg.tv_nsec;
	    	fprintf(fp2, "Time for %d: %.12f      (with %ld/%ld)\n", i, (elapsed/j)/1000000000.0, beg.tv_nsec, end.tv_nsec);
	}
	fclose(fp2);
	return 0;
}

// cache block size function
// cache size function
// main memory access time function
// cache memory access time function

//@Authors Ryan Ratliffe, Logan Sitar
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//To compile and run program using Makefile...
//	open terminal
//	cd to directoryName
//	make all			"compiles the code"
//	make run			"runs the code"
//	make blockReport		"shows the results, press 'q' to exit"
//	make cacheReport		"shows the results, press 'q' to exit"
//	make clean			"removes unecessary files"
//To change given inputs, open Makefile and change values of ARGS

//two global variables 
long max_its = 10000;
int byte = 1024;
int main(int argc, char** argv){
	// check correct num args
	if (argc != 4){
		printf("Usage: ./test <arraySize> <stepSize> <maxMBSize>\n");
		return 1;
	}//end of if
	//calls both methods that answer all 4 questions
	else {
		long aSize = atol(argv[1]);
		long max_step = atol(argv[2]);
		
		blockSize_accessTime(aSize, max_step);
		int max_MB = atol(argv[3]);
		cacheSize(max_MB);
		return 0;
	}//end of else
}//end of main

//questions 1, 3, 4 are answered in this method.
//the file will show you the elapsed time for each test, the ones with 
//higher access times are the ones at the beginning of a new block and 
//are main memory hits, all lower times are cache hits.
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
	    			//this is where the actual timed operation takes place	
				x = x + n[j];	
	    		}//end of j
	    		// take time here
			clock_gettime(CLOCK_MONOTONIC, &stop);
			//finishes taking time and calculates the 
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
  	}//end z loop
  	//close file
	fclose(fp);
	return 0;
}//end blockSize_accessTime

//answers question 2
//this method puts many elapsed times into the assosiated text 
//file, the lower ones are cached and the higher ones are not; 
//find a pattern interval and that is your cache size.
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
	    	//take time
	    	clock_gettime(CLOCK_MONOTONIC, &beg);
	    	for (i = 0; i < jumps; i++) {
	    		//actual operation being timed
	       	a[(i * 16) & len]++;
	    	}//end i loop
	    	//times the operation
	    	clock_gettime(CLOCK_MONOTONIC, &end);
	    	elapsed = end.tv_nsec - beg.tv_nsec;
	    	fprintf(fp2, "Time for %d: %.12f      (with %ld/%ld)\n", i, (elapsed/j)/1000000000.0, beg.tv_nsec, end.tv_nsec);
	}//end j loop
	//close file
	fclose(fp2);
	return 0;
}//end cacheSize

SitarRatliffe340Project
to run code refer to the first comment on the "driver.c" file. The project is built using makeFile.


Questions to Answer:
1. How big is a cache block?
- Around 88 bytes (2^6-2^7 bytes). This was determined due to the drastic jump in elapsed time that typically falls in this block when accessing data. The drastic jump in time signifies the loading of a new block into main memory.

2. How big is the cache?
- The cache is divided up into levels. L1d cache(32 KiB), L1i cache(32 KiB), L2 cache(256 KiB), and L3 cache (20 MiB) for a total of 20.32Mib. The size of the cache depends on the amount of storage you designated to your Virtual Box. The above sizes are for Ryan's computer. In order to check your virtual box's cache sizes, simply open up the terminal, and type "lscpu | grep cache" into the command line. This cache size was verified through our code because the access time significantly spiked about every 20MB, which lines up with the intel 10850k cpu we were running this on perfectly.

3. How long does a reference to main memory take to complete?
- On average this system’s main memory is taking around/up to 1.5ns to access the data. When it has to reach into the ram to pull out the information as opposed to the cache we can see the higher access time as each prefetched section becomes inadequate for the current operation. In our results we sometimes didn't see super conclusive data due to the high clock speed of the computer we were testing on. However all of the results we have seen are within margin of error and variance.

4. How long does a reference that can be satisfied from cache take to complete?
- When accessing pre-fetched data we see long periods of reduced access time around 1.3ns,  When cached due to fetching, data becomes way easier to access so we are able to see extended periods of reduced access time to know when it was a cache hit. Again our testing computer’s hardware’s speed and excessive amount of cache made results with large margins impossible. However all of the results are within variance of our testing.

Explanation of Code:
- In our code to derive the memory access times and determine block size we have three loops running in a nested formation to access the memory in the same way but with different increments. This allows us to keep running averages and refine most of the noise out of the data. Also due to the fast cpu we were using for many of the tests we were able to run extra large numbers to ensure the most accurate results possible. However the extremely fast access time greatly hampered our results because of the amount of noise introduced by the inaccuracy of our system’s counter/ timing system. Even beyond the inaccuracy of the counter we have the cpu’s tasks getting kicked off the cpu during our test and drastically altering numbers if the code gets paused in the wrong place. In the code that shows our solution to solve the cache size we ended up counting and accessing data based on an array that stored exactly 1MB and thus seeing how many megabytes were able to be stored in the cache. We then output the results from both of these methods into their respective text files for analysis.


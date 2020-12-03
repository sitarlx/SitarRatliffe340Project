SitarRatliffe340Project

Questions to Asnswer:
1. How big is a cache block?
- Around 88 bytes (2^6-2^7 bytes)

2. How big is the cache?
- The cache is divided up into levels. L1d cache(32 KiB), L1i cache(32 KiB), L2 cache(256 KiB), and L3 cache (20 MiB) for a total of 20.32Mib. The size of the cache depends on the amount of storage you designated to your Virtual Box. The above sizes are for Ryan's computer. In order to check your virtual box's cache sizes, simply open up the terminal, and type "lscpu | grep cache" into the command line. This cache size was verified through our code becasue the access time significantly spiked at what we deemed to be...

3. How long does a reference to main memory take to complete?
-

4. How long does a reference that can be satisfied from cache take to complete?
-

Explanation of Code:
- 

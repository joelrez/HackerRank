# HackerRank
In this repo, I am working on some HackerRank problems I found. With some that I find a sequential algorithm for, I try to also parallelize.

# Bird Sightings
Currently, I have the bird sighting problem parallelized. It will split the array into 5 chunks accross 5 threads, which I know in OpenMP is not always guaranteed to happen. We could request 5 threads and get at most 5 threads. Anyway, it will share the workload accross threads, and use a reduction on the shared array. I wasn't sure whether I should've split the computation into two for loops with one OMP and another sequential or just one with a reduction on all the results. I think doing the latter makes it faster, and it would seem it gives the correct result.

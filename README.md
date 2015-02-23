# WordListPuzzle
Running time for different sorting algorithims using the 15x15 grid

Searching with Hash table
Sorting Time: 0.03902s
Search Time: 0.050476s
Total Time: 0.103913s

Heap Sort
Sorting Time: 0.226781s
Search Time: 307.414s
Total Time: 307.643s

Merge Sort
Sorting Time: 0.199767s
Search Time: 318.01s
Total Time: 318.212s


Quick Sort
Sorting Time: 0.09577s
Search Time: 323.345s
Total Time: 323.442s

Insertion Sort 
Sorting Time: 66.3276s
Search Time: 314.561s
Total Time: 380.892s

 From the comparison, it is evident that the HashTable data structure is significantly faster 
 than any of data structures employing sorting algorithms. 
 The actual sorting times are only comparable between Heap Sort, Merge Sort, Quick Sort and Insertion Sort. 
 This is because Hash Table isn't actually a sorting algorithm, but rather an indexer, 
 that rediscovers a value's existence directly through the hash generator and the Hash Table. 
 The fastest sorting algorithm is Quick Sort with Merge Sort and Heap Sort taking about twice as long.
 Meanwhile, Insertion Sort took on order of 600 times longer to compute than Quick Sort.
  
 In terms of the total time, Hash Table wins by a huge margin. 
 It completed the search of the 15x15 board in .103 seconds while the next fastest was Heap Sort by an extra 307.50 seconds!!
 This proves that Hash Tables are a very effective way of storing elements. 
 The only draw back can be the space required to create the Hash Tables.
 Another factor is how well the hash function works, which requires a large, even distribution to be efficient.
 If the input entires aren't known apriori, then Hash Table may not be a very effective 
 method of storing elements because the hash table could have a very small distribution with excessive unused memory.



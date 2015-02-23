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

From the comparison, it is evident that the HashTable is significantly fast than any of the other of the sorting algorithms. The actual sorting times are only comparable between Heap Sort, Merge Sort, Quick Sort and Insertion Sort. This is because Hash Table doesn't actually a sorting algorithm, instead it hashes the word into a given index through the hash generator and entered into the Hash Table. The fastest sorting algorithm is Quick Sort but it is not sort in place so it requires external memory while the others don't. Within the sort in place algorithm, MergeSort seems to be the fastest. 
  
  The total time is still comparable though and Hash Table wins by a huge margin. It completed the search of the 15x15 board in .103 seconds while the next fastest was Heap Sort. This proves that Hash Tables are a very effective way of storing elements but the only draw back can be the space required to create the Hash Tables. Another factor is how well the hash function works, which requires a large distribution to be efficient. If the input entires aren't known, then Hash Table may not be a very effective method of storing elements because then the hash table could have a very small distribution.

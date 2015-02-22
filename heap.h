#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdexcept>
#include <exception>
#include <vector>
using namespace std;

// make heap a vector with expanded data & functionality
class Heap {
public:
	Heap(); // useless: utterly unequivocally unimportant. ugh.
	Heap(vector<string> input); // creates a max heap
	int parent(int i) {	return (i > 0) ? ((i - 1) / 2) : -1; } // gets the index of the parent: returns -1 for bastards
	int left(int i) { int a = (2 * (i + 1) - 1); return ((a < structuredheapsize) ? a : -1); } // gets the index of the left heap: -1 for non existent heaps
	int right(int i) { int a = (2 * (i + 1)); return ((a < structuredheapsize) ? a : -1); } // get the index of the right heap: -1 for non existent heaps
	string getItem(int i) {return data[i];} // gets the T(hing) at the index
	void setItem(int i, string gj) {	data[i] = gj; } // sets the T(hing) at the index
	void initializeMaxHeap(vector<string> input) { data = input; } // inputs a vector of T(hings)
	vector<string> getData() { return data; }
	int getHeapSize() {	return structuredheapsize; } // get the heap size
	void setHeapSize(int n) { structuredheapsize = n;	} // set the heap size
	int size() { return data.size(); } // get the vector size
	void buildMaxHeap(); // turns a heap structure into a valid maximum root heap
	void maxHeapify(int i); // makes a heap a valid maximum root heap
	void maxHeapSort();
	void dataSwap(int i, int j);
	virtual ~Heap();
protected:
	vector<string> data;
	int structuredheapsize;
};

#endif /* HEAP_H_ */

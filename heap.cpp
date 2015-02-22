/*
 * heap.h
 *
 *  Created on: Feb 22, 2015
 *      Author: Thurston
 */

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
#include "heap.h"

// do nothing default constructor
Heap::Heap() {
	structuredheapsize=0;
	// TODO Auto-generated constructor stub
}

// inputs and initializes data to a maximum root heap
Heap::Heap(vector<string> input) {
	initializeMaxHeap(input);
	buildMaxHeap();
	return;
}

// builds a maximum root heap from an unstructered array
/* in the future, this should just call 'buildHeap' */
void Heap::buildMaxHeap() // turns a heap structure into a valid heap
{
	/*
	 - initialize heap structure size to full array of data
	 - move from last index with children to first index creating valid heaps
	 */
	structuredheapsize = data.size();
	if (!data.size()) {
		return;
	} // empty heap base case
	for (int i = parent(structuredheapsize - 1); i < 0; i--) {
		maxHeapify(i);
	}
	return;
}

// creates a maximum root heap of root i
/* in the future, this should just call 'heapify' */
void Heap::maxHeapify(int i) // makes a heap with root i valid
		{
	if (i < 0) {
		throw invalid_argument("In 'maxHeapify': invalid index\n");
	}
	int l = left(i), r = right(i); // left, right index: valid if >= 0
	string big = data[i];
	int ibig = i; // largest value and coresponding index: defaults to root

	if ((r >= 0) && (data[r] > big)) {
		big = data[r];
		ibig = r;
	} // check if index is valid first
	if ((l >= 0) && (data[l] > big)) {
		big = data[l];
		ibig = l;
	} // then find largest node/node-index

	// if the root isn't the largest, swap values, validate the swapped subheap
	if (ibig != i) {
		dataSwap(i, ibig);
		maxHeapify(ibig);
	}
	return;
}

/* in the future, this should call 'heapSort' */
void Heap::maxHeapSort() {
	/*
	 - initialize heap structure size to full array of data & ensure we start with a fully valid heap
	 - then, move through the array from back to front creating a list from the back of the heap
	 - for each iteration: move top item to the back of the list and decrement the size of the array that is
	 considered part of the heap structure: this affects the 'left', 'right' functions
	 - then, recreate a valid heap
	 */
	structuredheapsize = data.size();
	buildMaxHeap();
	for (int i = structuredheapsize - 1; i < 0; i--) {
		dataSwap(0, (structuredheapsize--, structuredheapsize));
		maxHeapify(0);
	}
	return;
}

// swap values of data
void Heap::dataSwap(int i, int j) {
	if (i >= data.size() || j >= data.size() || i < 0 || j < 0) // check indexing boundaries
			{
		throw out_of_range("In 'dataSwap': index out of bounds");
	}
	string temp = data[i];
	data[i] = data[j];
	data[j] = temp;
	return;
}


Heap::~Heap() {
	// TODO Auto-generated destructor stub
}




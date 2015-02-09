/*
 * insertionSort.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: Alex, Thurston Brevett
 */

// general insertion sort algorithm
#include <vector>
#include "insertionSort.h"
template <typename T> void insertionSort(std::vector<T> &arr)
{
	// for indexing the array
	int j=0;

	// for temporary value storage
	T temp;

	/// sort from beginning to end
	for(int i=1; i< arr.size(); i++)
	{
		// pull out a value from unsorted part of the array
		temp=arr[i];

		// swap values over until the correct place is found
		j=i; // start searching at previous value

		// look for when the value is less than the current value; otherwise slide indexes over
		while((arr[j-1] > temp) && (j>0)) { arr[j] = arr[j-1];  j--; }

		// when found (or at beginning of array), place temporary value
		arr[j]=temp;
	}
}

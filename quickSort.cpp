/*
 * quickSort.cpp
 *
 *  Created on: Feb 5, 2015
 *      Author: alex
 */
#include <iostream>
using namespace std;
#include <vector>
#include "quickSort.h"



template <typename T> void quickSort(vector <T>& list, int left, int right)
{
	int s;
	if(left < right)
	{
		s = partition <T> (list, left, right);
		quickSort <T> (list , left, s-1);
		quickSort <T> (list, s+1, right);
	}
}
template <typename T> int partition(vector <T>& list, int left, int right)
{
	//set the pivot to the middle element of the list
	int pivotindex = (left + right)/2;

	T pivot = list[pivotindex];
	cout << "pivot value: " <<pivot << "size: "<<right-left+1<< endl;

	// put the pivot value at the end of the sub array
	T temp = list[pivotindex]; list[pivotindex]=list[right]; list[right]=temp;

	//set i and lessindex as the left most element, so the beginning of the list
	//set j as the right most element, so the last element in the current list
	int i = left, lessindex = left, j = right;

	// go through the list and move all values beneath the pivot to a lower index
	// keep track of the lesser value indices
	for(i=0;i<right;i++)
	{
		if(list[i] <= pivot)
		{
			temp           = list[i];
			list[i]        = list[lessindex];
			list[lessindex]= temp;
			lessindex++;
		}
	}
	temp           = list[lessindex];
	list[lessindex]= list[right];
	list[right]    = temp;
	return lessindex;
}




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

template <typename T>
void quickSort (vector <T>& list, int left, int right)
{
	int s;
	if(left < right)
	{
		s = partition (list, left, right);
		quickSort (list , left, s-1);
		quickSort (list, s +1, right);
	}
}

template <typename T>
int partition (vector <T>& list, int left, int right)
{
	//set the pivot to the middle element of the list
	int pivot = list[(left + right)/2];
	cout << "pivot value " <<pivot << endl;
	//create a temporary variable for when the swapping needs to occur
	int temp;
	//set i as the left most element, so the beginning of the list
	int i = left;
	//set j as the right most element, so the last element in the current list
	int j = right+1;
	//loops while i is less then j because once i > j then the list has been fully partitioned
	while(i <= j)
	{
		//if the value of the current value is less the then pivot then ignore it
		while(list[i] < pivot)
		{
			i++;
		}
		//ignores cases where the value of the element to the left of the pivot is greater then the pivot
		//because then it is in the correct spot already
		while(list[j] > pivot)
		{
			j--;
		}
		//while the case that that i is still less the j then swap j and i because they are in the wrong
		//locations
		if(i <= j)
		{
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
			i++;
			j++;
		}
	}
	return j;
}




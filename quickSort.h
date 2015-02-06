/*
 * quickSort.h
 *
 *  Created on: Feb 5, 2015
 *      Author: alex
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_
#include <iostream>
using namespace std;
#include <vector>

template <typename T>
void quickSort (vector <T>& list, int left, int right);

template <typename T>
int partition (vector <T>& list, int left, int right);



#endif /* QUICKSORT_H_ */

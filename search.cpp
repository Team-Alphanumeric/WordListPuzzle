/*
 * search.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: Alex, Thurston
 */

#include <time.h>
#include <cstring>
#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <stdlib.h>
#include "Grid.h"
#include "Wordlist.h"
#include "findMatches.h"
using namespace std;

void search(const int sortType, const int gridsize=15)
{
	// declare a string which holds the file name
	std::string gridname;
	
	//switch statement to decide the size of the grid based off the integer inputed by the user
	if(gridsize<0) {throw invalid_argument("in 'search': invalid argument"); }
	switch(gridsize)
	{
		case 15: gridname = "input15.txt"; break;
		case 30: gridname = "input30.txt"; break;
		case 50: gridname = "input50.txt"; break;
		case 250: gridname = "input250.txt"; break;
		default: gridname = "input15.txt"; break;
	}
	//declare classes
	Grid g(gridname);
	Wordlist w("wordList.txt");

	clock_t start = clock(), sorttime, searchtime;

	// sort the list based off the inputed value: 0= InsertionSort, 1=QuickSort, 2=mergeSort
	w.sortList(sortType); sorttime = clock(); // get the time after sorting
	
	// find matches in the sorted wordlist
	findMatches(w,g); searchtime = clock(); // get the time after searching
	
	// print out time spent for each operation
	cout << "Sorting Time: " << (float) (sorttime-start)/CLOCKS_PER_SEC << "s" << endl;
	cout << "Search Time: " <<  (float) (searchtime-sorttime)/CLOCKS_PER_SEC << "s" << endl;
	cout << "Total Time: " <<   (float) (clock()-start)/CLOCKS_PER_SEC << "s" << endl;
}


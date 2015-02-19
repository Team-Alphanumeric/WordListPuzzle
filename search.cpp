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

void search(const int sortType, const int puzzleNum=1)
{
	// declare a string which holds the file name
	std::string gridname;

	//switch statement to decide the size of the grid based off the integer inputed by the user
	if(puzzleNum<0 || puzzleNum>8) {throw invalid_argument("in 'search': invalid argument"); }
	switch(puzzleNum)
	{
		case 1: gridname = "input15.txt"; break;
		case 2: gridname = "input30.txt"; break;
		case 3: gridname = "input50.txt"; break;
		case 4: gridname = "puzzle3_size50.txt"; break;
		case 5: gridname ="puzzle4_size100.txt"; break;
		case 6: gridname = "input250.txt"; break;
		case 7: gridname = "puzzle5_size500.txt"; break;
		case 8: gridname = "puzzle6_size1000.txt"; break;
		default: gridname = "input15.txt"; break;
	}
	cout << "Searching Puzzle " << gridname << endl;
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


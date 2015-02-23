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
	// if statement differentiates which data structure is being used.
	// If the sorting type will be insertion sort ,quick sort, or merge sort then
	// the data will be read into a vector then sorted, if it is the hash table, then the
	// elements need to be entered into the hash table using the hash function

	clock_t start, sorttime, searchtime;
	if(sortType == 3)
	{
		Wordlist w;
		w.setDataType(1); start = clock();
		w.readWordsHash("wordList.txt"); sorttime = clock();
		findMatches(w,g); searchtime = clock(); // get the time after searching
	}
	else
	{
		try
		{
			Wordlist w("wordList.txt");
			w.setDataType(0); start = clock();
			// sort the list based off the inputed value: 0= InsertionSort, 1=QuickSort, 2=mergeSort
			w.sortList(sortType); sorttime = clock(); // get the time after sorting

			// find matches in the sorted wordlist
			findMatches(w,g); searchtime = clock(); // get the time after searching
		}
		catch(invalid_argument &e)
		{
			cout << "Exception found in Wordlist constructor " << e.what() << endl;
		}
		catch(exception &e)
		{
			cout << "Unspecified error in search.cpp" << e.what() << endl;
		}


	}

	// print out time spent for each operation
	cout << "Sorting Time: " << (float) (sorttime-start)/CLOCKS_PER_SEC << "s" << endl;
	cout << "Search Time: " <<  (float) (searchtime-sorttime)/CLOCKS_PER_SEC << "s" << endl;
	cout << "Total Time: " <<   (float) (clock()-start)/CLOCKS_PER_SEC << "s" << endl;
}


/*
 * search.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: Alex, Thurston
 */

#include <time.h>
#include "Grid.h"
#include "Wordlist.h"
#include <cstring>
#include <string>
#include <iostream>
#include "findMatches.h"
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

void search(const int sortType, const int gridsize=15)
{
	// declare a string which holds the file name
	std::string gridname;
	//switch statement to decide the size of the grid based off the integer inputed by the user
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
	clock_t start = clock(), sorttime, searchtime;
	Wordlist w("wordList.txt");
	//sorts the list based off the inputed value of the user. 0= InsertionSort, 1=QuickSort, 2=mergeSort
	//calculate the CPUS time to sort
	w.sortList(sortType); sorttime = clock();
	//find matches in the sorted wordlist
	//calculate the CPU time to search
	findMatches(w,g); searchtime = clock();
	//print out eh CPU times
	cout << "Sorting Time: " << (float) (sorttime-start)/CLOCKS_PER_SEC << endl;
	cout << "Search Time: " << (float) (searchtime-sorttime)/CLOCKS_PER_SEC << endl;
	cout << "Total Time: " <<(float) (clock()-start)/CLOCKS_PER_SEC << endl;
}




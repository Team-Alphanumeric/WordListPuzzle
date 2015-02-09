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
	std::string gridname;
	switch(gridsize)
	{
		case 15: gridname = "input15.txt"; break;
		case 30: gridname = "input30.txt"; break;
		case 50: gridname = "input50.txt"; break;
		case 250: gridname = "input250.txt"; break;
		default: gridname = "input15.txt"; break;
	}
	Grid g(gridname);
	clock_t start = clock(), sorttime, searchtime;
	Wordlist w("wordList.txt");
	w.sortList(sortType); sorttime = clock();
	findMatches(w,g); searchtime = clock();
	cout << "Sorting Time: " << (float) (sorttime-start)/CLOCKS_PER_SEC << endl;
	cout << "Search Time: " << (float) (searchtime-sorttime)/CLOCKS_PER_SEC << endl;
	cout << "Total Time: " <<(float) (clock()-start)/CLOCKS_PER_SEC << endl;
}




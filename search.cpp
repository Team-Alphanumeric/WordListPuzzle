//============================================================================
// Name        : WordListPuzzle.cpp
// Author      : Alex Agudelo, Thurston Brevett
// Version     : Project 2a
// Copyright   :
// Description : Executes a word search on a grid of letters corresponding to
// 				 a list of words
//============================================================================

#include <iostream>
#include <stdexcept>
#include <exception>
#include "d_except.h"
#include "Wordlist.h"
#include "Grid.h"
#include "findMatches.h"
#include "insertionSort.h"
#include "search.h"
using namespace std;

// executes a word search
int main(void)
{
	try
	{
		// execute a search
		// arg1: 0 -> insertion sort, 1 -> quick sort, 2-> merge sort
		// arg2: the puzzle number, 1-8, with puzzle size, 15,30,50,50,100,250,500,1000
		search(2, 8);
		return 0;
	}
	catch(exception &e)
	{
		cout <<"In 'main': " << e.what() << endl;
	}
	catch(baseException &e)
	{
		cout <<"In 'main': " << e.what() << endl;
	}
	catch(...)
	{
		cout<<"In 'main': Unknown exception " << endl;
	}
	return -1;
}

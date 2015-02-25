/*
 * Grid.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: Alex, Thurston
 */

#include "Grid.h"

/* Implements the grid class for a word search which holds and accesses a character matrix
*/

#include "d_execpt.h"
#include "matrix.h"
#include "Grid.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
#include <exception>


const int Grid::getSize() {return size;}

// return the corresponding character: accepts negative indices up to the size of the dimension
const char Grid::getChar(const int m, const int n)
{ return lttrs[(m+size+size+size) % size][(n+size+size+size) % size]; }

// initialize a grid to an empty grid
Grid::Grid() {size = 0; lttrs.resize(0);}

// initialize a grid with a txt file
Grid::Grid(const string filename)
{
	try{ setGrid(filename);	}
	catch( indexRangeError &e)
	{ cout << "Invalid Range Error at " << e.what() << endl; }

}

// sets the grid to the values of the given file
void Grid::setGrid(string filename)
{
	// open file
	ifstream gridfile(filename.c_str());
	gridfile.exceptions (ifstream::failbit | ifstream::badbit);
	try
	{

		// get the size of the grid from the first line in the file
		gridfile >> size >> size;

		// resize the vectors according to the size of the grid
		lttrs.resize(size); for(int i=0; i<size; i++) { lttrs[i].resize(size); }

		for(int j=0; j < size; j++)
		{
			for(int i=0; i < size ; i++)
			{
				// check that there are enough characters for the grid
				if((gridfile.eof()) && (i<size-1) && (j<size-1))
				{
					throw indexRangeError("In 'setGrid': grid size larger then number of characters", i, j );
				}

				gridfile >> lttrs[j][i]; // enter letters into the file
			}
		}
		gridfile.close();
	}
	catch(ifstream::failure &e)
	{
		cout <<  "In 'setGrid': unable to open/read file:\n" << e.what();
	}
}

//this function returns an ostream with the string containing all the words
ostream& operator<< (ostream &ostr, Grid gj)
{
	//declare constants
	string temp = "";

	for(int i=0;i<gj.getSize();i++)
	{
		for(int j=0; j<gj.getSize(); j++)
		{
			ostr << gj.getChar(i,j) << " "; // enter the character into the grid
		}
		ostr << "\n";
	}
	//return the ostr with the temp string
	return ostr;

}

Grid::~Grid() {
	// TODO Auto-generated destructor stub
}


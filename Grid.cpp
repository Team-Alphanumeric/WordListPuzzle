/*
 * Grid.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: alex
 */

#include "Grid.h"

/* Implements the grid class for a word search which holds and accesses a character matrix
*/

#include "d_except.h"
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


const int Grid::getSize() {return size;}

const char Grid::getChar(const int m, const int n)
{ return lttrs[(m+size) % size][(n+size) % size]; }

Grid::Grid() {size = 0;}

Grid::Grid(const string filename) { setGrid(filename); }
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
				gridfile >> lttrs[j][i];
			}
			cout<<endl;
		}
		gridfile.close();
	}
	catch(ifstream::failure &e)
	{
		cout <<  "Exception opening/reading file in readWords function of Wordlist class:" << e.what();
	}
}

ostream& operator<< (ostream &ostr, Grid gj)
{
	//declare constants
	string temp = "";

	//this puts all the words into one string with end line characters after each word
	//this function returns an ostream with the string containing all the words
	for(int i=0;i<gj.getSize();i++)
	{
		for(int j=0; j<gj.getSize(); j++)
		{
			ostr << gj.getChar(i,j) << " ";
		}
		ostr << "\n";
	}
	//return the ostr with the temp string
	return ostr;

}

Grid::~Grid() {
	// TODO Auto-generated destructor stub
}


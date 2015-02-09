/*
 * Grid.h
 *
 *  Created on: Feb 8, 2015
 *      Author: alex
 */

#ifndef GRID_H_
#define GRID_H_
#include <string>
#include "matrix.h"

class Grid {
public:
	Grid();
	Grid(const string filename);
	void setGrid(const string filename);
	const char getChar(const int m, const int n);
	const int getSize();
	friend ostream& operator<< (ostream &ostr, Grid gj);
	virtual ~Grid();
protected:
		vector< vector<char> > lttrs;
		int size;
};

#endif /* GRID_H_ */

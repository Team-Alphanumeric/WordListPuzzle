/*
 * matrix.h
 *
 *  Created on: Feb 8, 2015
 *      Author: alex
 */

#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include <iostream>
#include <vector>

#include "d_execpt.h"

using namespace std;

template <typename T>
class matrix
{
  public:
   matrix(int numRows = 1, int numCols = 1, const T& initVal = T());
   // constructor.
   // Postcondition: create array having numRows x numCols elements
   // all of whose elements have value initVal

   vector<T>& operator[] (int i);
   // index operator.
   // Precondition: 0 <= i < nRows. a violation of this
   // precondition throws the indexRangeError exception.
   // Postcondition: if the operator is used on the left-hand
   // side of an assignment statement, an element of row i
   // is changed

   const vector<T>& operator[](int i) const;
   // version for constant objects

   int rows() const;
   // return number of rows
   int cols() const;
   // return number of columns

   void resize(int numRows, int numCols);
   // modify the matrix size.
   // Postcondition: the matrix has size numRows x numCols.
   // any new elements are filled with the default value of type T

  private:
   int nRows, nCols;
   // number of rows and columns

   vector<vector<T> > mat;
   // matrix is implemented as nRows vectors (rows),
   // each having nCols elements (columns)
};
#endif	// MATRIX_CLASS

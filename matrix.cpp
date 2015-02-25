/*
 * matrix.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: alex
 */

#include "matrix.h"
#include <exception>
#include <stdexcept>
#include "d_execpt.h"

template <typename T>
matrix<T>::matrix(int numRows, int numCols, const T& initVal):
	nRows(numRows), nCols(numCols),
	mat(numRows, vector<T>(numCols,initVal))
{}

// non-constant version. provides general access to matrix
// elements
template <typename T>
vector<T>& matrix<T>::operator[] (int i)
{
   if (i < 0 || i >= nRows)
      throw indexRangeError(
	 "matrix: invalid row index", i, nRows);

   return mat[i];
}

// constant version.  can be used with a constant object.
// does not allow modification of a matrix element
template <typename T>
const vector<T>& matrix<T>::operator[] (int i) const
{
   if (i < 0 || i >= nRows)
      throw indexRangeError(
	 "matrix: invalid row index", i, nRows);

   return mat[i];
}

template <typename T>
int matrix<T>::rows() const
{
   return nRows;
}

template <typename T>
int matrix<T>::cols() const
{
   return nCols;
}

template <typename T>
void matrix<T>::resize(int numRows, int numCols)
{
   int i;

   // handle case of no size change with a return
   if (numRows == nRows && numCols == nCols)
      return;

   // assign the new matrix size
   nRows = numRows;
   nCols = numCols;

   // resize to nRows rows
   mat.resize(nRows);

   // resize each row to have nCols columns
   for (i=0; i < nRows; i++)
      mat[i].resize(nCols);
}



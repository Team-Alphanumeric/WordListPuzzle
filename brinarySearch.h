/*
 * binarySearch.h
 *
 *  Created on: Feb 6, 2015
 *      Author: Alex, Thurston
 */

#ifndef BINARYSEARCH_H_
#define BINARYSEARCH_H_

using namespace std;
#include <string>
#include <vector>

bool binSearch(vector <string> wordlist, string wordTarget, int low, int high, bool (*op) (string,string));

bool stringEqual(string lhs, string rhs);

bool stringPrefix(string pre, string word);

#endif /* BINARYSEARCH_H_ */

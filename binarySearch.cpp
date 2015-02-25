/*
 * binarySearch.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: Alex, Thurston
 */

#include "binarySearch.h"
using namespace std;
#include <string>
#include <vector>
#include "d_execpt.h"


bool binSearch(vector <string> wordlist, string wordTarget, int low, int high, bool (*op)(string,string))
{
	// determine partition bounds
	int mid = ((low + high)/2);

	if(low > high)	{ return false;	}  // base case: index out of bounds, not here

	// double check partition bounds
	if((low<0) || (low>=wordlist.size())) {throw indexRangeError("In 'binSearch': Lower index out of bounds", low, wordlist.size());}
	if((mid<0) || (mid>=wordlist.size())) {throw indexRangeError("In 'binSearch': Middle index out of bounds",low, wordlist.size()); }
	if((high<0) || (high>=wordlist.size())) {throw indexRangeError("In 'binSearch': Upper index out of bounds",low, wordlist.size()); }


	if((*op) (wordTarget, wordlist[mid])) { return true; } // success of operand: found it!
	else
	{
		if(wordTarget<wordlist[mid]) // search lower side
		{
			return binSearch(wordlist,wordTarget,low,mid-1,op);
		}
		else // search upper side
		{
			return binSearch(wordlist, wordTarget,mid+1,high,op);
		}
	}

	return false;
}

// returns whether two strings are equal
bool stringEqual(string lhs, string rhs) {return lhs == rhs; }

// checks if 'pre' is a prefix for the word
bool stringPrefix(string pre, string word)
{
	// check that the sizes are consistent with 'pre' being a prefix
	bool match = pre.size() < word.size();
	if(match)
	{
		// implement character by character checking across 'pre' and 'word'
		// only traverses the length of 'pre' since 'word' is longer than 'pre'
		for(int i=0;i<pre.size();i++)
		{ match = match && (pre[i]==word[i]); }
	}
	// return result of checks
	return match;
}


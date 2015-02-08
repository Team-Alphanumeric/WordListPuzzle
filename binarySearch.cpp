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

bool binSearch(vector <string> wordlist, string wordTarget, int low, int high, bool (*op) (string,string))
{
	int mid = ((low + high)/2);
	bool result;

	if(low > high)	{ return false;	}  // out of bounds, not here


	if((*op) (wordTarget, wordlist[mid])) // found it!
	{ return true; }
	else
	{
		if(wordTarget<wordlist[mid]) // search lower side
		{
			result = binSearch(wordlist,wordTarget,low,mid-1,op);
		}
		else // search upper side
		{
			result =  binSearch(wordlist, wordTarget,mid+1,high,op);
		}
	}

	return result;
}

// returns whether two strings are equal
bool stringEqual(string lhs, string rhs) {return lhs == rhs; }

// checks if 'pre' is a prefix for the word
bool stringPrefix(string pre, string word)
{
	// check that the sizes are consistent
	bool match = (pre.size() <= word.size());
	if(match)
	{
		// implement character by character checking across 'pre' and 'word'
		for(int i=0;i<pre.size();i++)
		{ match = match && (pre[i]==word[i]); }
	}
	// return result of checks
	return match;
}


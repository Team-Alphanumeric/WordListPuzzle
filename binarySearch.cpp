/*
 * binarySearch.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: alex
 */

#include "binarySearch.h"
using namespace std;
#include <string>
#include <vector>

bool binSearch(vector <string> wordlist, string wordTarget, int low, int high)
{
	int mid = ((low + high)/2);
	bool result;

	if(low > high)
	{
		result = false;
	}
	else
	{
		if(wordTarget==wordlist[mid])
		{
			result = true;
		}
		else
		{
			if(wordTarget<wordlist[mid])
			{
				result = binSearch(wordlist,wordTarget,low,mid-1);
			}
			else
			{
				if(wordTarget>wordlist[mid])
				{
					result =  binSearch(wordlist, wordTarget,mid+1,high);
				}
				else
				{
					result =  false;
				}
			}

		}
	}
	return result;


}



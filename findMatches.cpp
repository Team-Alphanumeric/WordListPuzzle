/*
 * findMatches.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: alex
 */

#include "findMatches.h"
#include "Wordlist.h"
#include <string>
using namespace std;
#include <iostream>
#include <cstdio>

void findMatches(Wordlist w1, Grid g1)
{
	int i,j; // indexes for the letters in the grid
	int x,y; // values to define offset direction
	int len=0; // length of the current word
	char *ch=0; // temporary character
	bool remmatch=true; // whether possible matches are remaining
	string newword; // word created from letters in the grid
	for(i=0;i<g1.getSize();i++)
	{
		for(j=0;j<g1.getSize();j++)
		{
			for(x=-1;x<=1;x++)
			{
				for(y=-1;y<=1;y++)
				{
					// create a new word starting from this position in the grid (length of word is 0)
					newword.resize(0); len=0;
					// default remaining matches? should be true:
					// set 'remmatch' false if direction is (0,0) to skip searching in null direction
					remmatch = (x||y);
					// build a new word by going through the grid and check it with the list
					while(remmatch) // continue if there are still matches are remaining
					{
						// add a character to the word
						*ch=(g1.getChar(i+(len*x),j+(len*y)));
						newword.append(ch); len++;
						// if it's at least 5 letters, check if it matches a specific word
						if(newword.size()>=5)
						{
							// if it matches exactly, print it, then keep searching
							if(w1.existWord(newword))
							{ cout << newword << "\n"; remmatch=true; }
							else // otherwise, see if there are other possible matches starting with this word
							{
								remmatch = w1.prefix(newword);
							}
						}
					}
				}
			}
		}
	}
}


/*
void checkRightHor(Wordlist w1, Grid g1, int horPos, int verPos)
{
	int startHorPos;
	startHorPos=horPos;
	bool wrapCheck;
	bool result;
	string potentWord;
	//checks for possible words in the right direction
	wrapCheck =true;
	while(wrapCheck)
	{
		potentWord += g1.getChar(horPos,verPos);
		horPos++;
		if(potentWord.size()>=5)
		{
			result = w1.existWord(potentWord);
			if(result==true)
			{
				cout << potentWord << endl;
			}
		}
		if(horPos==g1.getSize())
		{
			horPos=0;
		}
		if(horPos==startHorPos)
		{
			wrapCheck=false;
		}

	}
	cout << "End of checking the right direction " << endl;
}
*/



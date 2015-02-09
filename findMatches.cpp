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

void findMatches(Wordlist w1, Grid gj)
{
	int i,j; // indexes for the letters in the grid
	int x,y; // values to define offset direction
	int len=0; // length of the current word
	char ch='\0'; // temporary character
	bool rem=true; // whether possible matches are remaining
	string newword; // word created from letters in the grid
	for(i=0;i<gj.getSize();i++) // for every row
	{
		for(j=0;j<gj.getSize();j++) // for every column
		{
			for(x=-1;x<=1;x++) // for every horizontal direction 
			{
				for(y=-1;y<=1;y++) // for every vertical direction
				{
					// create a new word starting from this position in the grid (length of word is 0)
					newword.resize(0); len=0;

					// default remaining matches ('rem') should start as true when building new words
					// set 'rem' false only if direction is (0,0) to skip searching in null direction
					rem = (x||y);

					// build a new word by going through the grid and checking the created word with the word list
					while(rem) // continue if there are still matches are remaining
					{
						// add a character to the word
						ch = (gj.getChar(i+(len*x),j+(len*y)));
						newword.push_back(ch); len++;
						
						// if it's at least 5 letters, check if it matches anything
						if(newword.size() >= 5)
						{
							// if it matches another word exactly, print it, then keep searching
							if(w1.existWord(newword)) { cout << newword << "\n"; rem=true; }
							
							// otherwise, see if there are other possible matches starting with this word
							else { rem = w1.prefix(newword); }
						}
					}
				}
			}
		}
	}
}


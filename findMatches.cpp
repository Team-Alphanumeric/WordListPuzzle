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

void findMatches(Wordlist w1, Grid g1)
{
	int i,j;
	for(i=0;i<g1.getSize();i++){
		for(j=0;j<g1.getSize();j++)
		{

		}
	}

}
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
			result = w1.compareWord(potentWord);
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



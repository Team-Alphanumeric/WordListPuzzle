/*
 * Wordlist.cpp
 *
 *  Created on: Feb 4, 2015
 *      Author: Alex, Thurston
 */

#include "Wordlist.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <stdio.h>
#include <string.h>
#include <stdexcept>
#include "binarySearch.h"
#include "d_except.h"

Wordlist::Wordlist()
{
	wds.resize(1);
}
/** readWords: Member function of Wordlist
 *  readWords takes the given file and inputs all the words in that file into the vector wds which
 *  is a data member of word list. This function assumes that the given file has one word per line.
 *  @ param string filename - This input is the name of the file that is going to be read and stored in wds
 *  @ return -void
 */
void Wordlist::readWords(const string filename)
{
	// declare constants
	int i=0;;
	//open myFile which is the file inputed and creates an instream for that file
	ifstream myFile;

	//tests the ability to open the file, if the file is able to be opened, then it starts storing the data
	//otherwise it throws an exception
	myFile.exceptions (ifstream::failbit | ifstream::badbit);
	try
	{
		myFile.open(filename.c_str());
		//while loop runs as long as there a word in a line to store into the vector wds
		//getline, stores all the characters stored in one line of the text file into the vector
		while(getline (myFile, wds[i]))
		{
			//prints out the word for verification that the word was stored correctly
			//cout << wds[i] << endl;
			wds.push_back("");
			//increment the word list
			i++;
		}
		//close the file once all the words have been transfered into the data member wds.
		myFile.close();
	}
	//catch statement sees if an error is thrown whether the file can be read or not
	catch(ifstream::failure &e)
	{
		cout <<  "Exception opening/reading file in readWords function of Wordlist class";
	}
}
/**
 * getVectorSize() returns the current size of its data member wds.
 * In otherwords, it returns the number of current words in the Wordlist
 *
 * @ return -returns the size of the data member wds
 */
int Wordlist::getVectorSize()
{ return wds.size(); }
/**
 * getWord(int index) returns the word in its data member wds with that index
 * Therefore it retrieves the word at the given index
 * @ param int index -the number of the index in wds to select
 * @ return - returns the word at that index
 */
string Wordlist::getWord(const int index)
{
	try{return wds[index];}
	catch(const out_of_range& oor)
	{ cout << "Out of Range Error when Retrieving word from Wordlist: " << oor.what(); return "";}
}
/**
 *  compareWord uses a binary search to serach for a word in the word list and returns true
 *  if the inputed word matches a word in the list
 *
 *  @param string word -an inputed word that is compared against the word list to see if there is a matching word
 *  @return boolean, -returns true if there is a matching word, returns false if there is no matching word
 */
bool Wordlist::existWord(string word1)
{ return binSearchWordList(wds,word1); }
/**
 * binSearchWordList changes the interface of binary search to have the user just enter in the vector and the list
 * and then it automatically sets the bounds to make using the function easier. This function then calls the binary
 * Search function with the correct bounds
 *
 * @param vector<string> wordlist -contains all the words that are to be compared to the grid
 * @param - wordTarget -word that is being searched for to see if it exist.
 * @return -returned boolean of either true if the word is in the list or false if it isn't
 */
bool Wordlist::binSearchWordList(vector <string> wordlist, string wordTarget)
{ return binSearch(wds,wordTarget,0,wds.size()-1,stringEqual); }

bool Wordlist::prefix(string word1)
{
	return binSearch(wds,word1,0,wds.size()-1,stringPrefix);
}
/**
 * getVector() returns the vector which contains a list of words
 * @return vector <string> -returns the vector that contains the word list
 */
vector <string> Wordlist::getVector() { return wds; }

//overloading operator for << that prints out all the words stored in the wordlist, aka wds vector
ostream& operator<< (ostream &ostr, Wordlist w1)
{
	//declare constants
	string temp = "";
	int i=0;
	//this puts all the words into one string with end line characters after each word
	//this function returns an ostream with the string containing all the words
	for(i=0;i<w1.getVectorSize();i++)
	{
		//appends each word to the temp string variable so that all the words are
		//stored in one string
		temp.append(w1.getWord(i));
		temp.append("\n");
	}
	//return the ostr with the temp string
	return ostr << temp;

}
Wordlist::~Wordlist() {
	// TODO Auto-generated destructor stub
}


/*
 * Wordlist.cpp
 *
 *  Created on: Feb 4, 2015
 *      Author: alex
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
	{ cout << "Out of Range Error when Retrieving word from Wordlist: " << oor.what() << endl;	}
	return "OutOfRange";

}

vector <string> Wordlist::getVector()
{
	return wds;
}

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
/**
 * quiSort(const vector <string> list) takes in a vector of type T and sorts it using quicksort
 * this is the quiSort function that the user will call because it has reduced arguments from the normal quickSort function
 */
void Wordlist::quiSort()
{
	quickSort <string> (wds, 0 , wds.size());
}
/**
 * quickSort is a sorting algorithim that sorts the elements in the list from smallest to greater
 * This sorting algorithim is templated to support multiple data types
 * The < operator must be overloaded for certain data types to work namely strings
 * @
 */
template <typename T>
void Wordlist::quickSort(const vector <T> list, int left, int right)
{
	int s;
	if(left < right)
	{
		s = partition <string> (list, left, right);
		quickSort <string> (list , left, s-1);
		quickSort <string> (list, s +1, right);
	}
}
template <typename T>
int Wordlist::partition(const vector <T> list, int left, int right)
{
	//set the pivot to the middle element of th elist
	T pivot = list((left + right)/2);
	//create a temperary variable for when the swaping needs to occur
	T temp;
	//set i as the left most element, so the beginning of the list
	int i = left;
	//set j as the right most element, so the last element in the current list
	int j = right+1;
	//loops while i is less then j because once i > j then the list has been fully partitioned
	while(i <= j)
	{
		//if the value of the current value is less the then pivot then ignore it
		while(list(i) < pivot)
		{
			i++;
		}
		//ignores cases where the value of the element to the left of the pivot is greater then the pivot
		//because then it is in the correct spot already
		while(list(j) < pivot)
		{
			j--;
		}
		//while the case that that i is still less the j then swap j and i because they are in the wrong
		//locations
		if(i <= j)
		{
			temp = list(i);
			list(i) = list(j);
			list(j) = temp;
			i++;
			j++;
		}
	}
	return j;
}
bool operator< (const string lhs, const string rhs)
{
	int result;
	result = lhs.compare(rhs);
	if(result > 0)
	{
		return true;
	}
	else if(result <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
Wordlist::~Wordlist() {
	// TODO Auto-generated destructor stub
}


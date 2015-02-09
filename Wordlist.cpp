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
#include "mergeSort.h"

Wordlist::Wordlist()
{
	wds.resize(1);
}

// initialize with a file
Wordlist::Wordlist(string filename)
{
	readWords(filename);
}

void Wordlist::sortList(int opt)
{
	switch(opt)
	{
	case 2:	wds = mergeSort<string>(wds,0,wds.size()-1); break;
	case 1: quickSort<string>(wds,0,wds.size()-1); break;
	default: insertionSort<string>(wds); break;
	}
}
/** readWords: Member function of Wordlist
 *  readWords takes the given file and inputs all the words in that file into the vector wds which
 *  is a data member of word list. This function assumes that the given file has one word per line.
 *  @ param string filename - This input is the name of the file that is going to be read and stored in wds
 *  @ return -void
 */
void Wordlist::readWords(const string filename)
{
	// temporary string variable
	string temp;

	//open myFile which is the file inputed and creates an instream for that file
	ifstream myFile(filename.c_str());

	//tests the ability to open the file, if the file is able to be opened, then it starts storing the data
	//otherwise it throws an exception
	myFile.exceptions (ifstream::failbit | ifstream::badbit);
	try
	{
		// while loop runs as long as there a word in a line to store into the vector wds
		// getline, stores all the characters stored in one line of the text file into the vector
		while(!myFile.eof())
		{
			getline(myFile,temp); // enter a line into the temporary variable
			wds.push_back(temp); // add this item to the list
		}
		//close the file once all the words have been transfered into the data member wds.
		myFile.close();
	}
	//catch statement sees if an error is thrown whether the file can be read or not
	catch(ifstream::failure &e)
	{
		cout <<  "Exception opening/reading file in readWords function of Wordlist class:" << e.what();
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
bool Wordlist::existWord(string wordTarget)
{ return binSearch(wds,wordTarget,0,wds.size()-1,stringEqual);  }
/**
 * prefix: searches for whether the given word is a prefix for any word in the wordlist
 * @param string bj - a string to check if it is a prefix
 */
bool Wordlist::prefix(string bj)
{
	return binSearch(wds,bj,0,wds.size()-1,stringPrefix);
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

template <typename T> void insertionSort(std::vector<T> &arr)
{
	// for indexing the array
	int j=0;

	// for temporary value storage
	T temp;

	/// sort from beginning to end
	for(int i=1; i < arr.size(); i++)
	{
		// cout<<"i @ " << i << "\n";
		// pull out a value from unsorted part of the array
		temp=arr[i];

		// swap values over until the correct place is found
		j=i; // start searching at previous value

		// look for when the value is less than the current value; otherwise slide indexes over
		while((j>0) && (arr[j-1] > temp))
		{
			arr[j] = arr[j-1];
			j--;
		}

		// when found (or at beginning of array), place temporary value
		arr[j]=temp;
	}
}

template <typename T> void quickSort(vector <T>& list, int left, int right)
{
	if(left < right)
	{
		int s = partition <T> (list, left, right);
		quickSort <T> (list, left, s-1);
		quickSort <T> (list, s+1, right);
	}
	return;
}

template <typename T> int partition(vector <T>& list, int left, int right)
{
	//set the pivot to the middle element of the list
	int pivotindex = (left + right)/2;

	T pivot = list[pivotindex];
	 //cout << "pivot value: " <<pivot << "\tsize: "<<right-left+1<< endl;

	// put the pivot value at the end of the sub array
	T temp = list[pivotindex]; list[pivotindex]=list[right]; list[right]=temp;

	//set i and lessindex as the left most element, so the beginning of the list
	//set j as the right most element, so the last element in the current list
	int i = left, lessindex = left, j = right;

	// go through the list and move all values beneath the pivot to a lower index
	// keep track of the lesser value indices
	for(i=left;i<right;i++)
	{
		if(list[i] <= pivot)
		{
			temp           = list[i];
			list[i]        = list[lessindex];
			list[lessindex]= temp;
			lessindex++;
		}
	}
	temp           = list[lessindex];
	list[lessindex]= list[right];
	list[right]    = temp;
	return lessindex;
}
template <typename T> vector<T> mergeSort(vector <T>& list, int left, int right)
{
	// list to create values
	vector<T> newlist;
	if(right==left) { newlist.push_back(list[right]); }

	// check for base case: length of list is invalid: array is sorted
	if((right-left)<=0) {return newlist;}

	// break the array into two (~equal) parts and sort them
	int center = (right+left)/2;
	vector<T> lhlist = mergeSort(list,left,center);
	vector<T> rhlist = mergeSort(list,center+1,right);

	// merge the two sorted pieces
	int i=0, j=0;


	// check index boundaries
	bool iout = i>=lhlist.size();
	bool jout = j>=rhlist.size();

	while(!iout || !jout) // quit when both indices are out of bounds
	{
		// if both indices are in bounds, add the lower value
		if(!iout && !jout)
		{
			if( lhlist[i] < rhlist[j] )
			{ newlist.push_back(lhlist[i]); i++; }
			else
			{ newlist.push_back(rhlist[j]); j++; }

		}
		// if left list only is out of bounds
		if(iout && !jout) { newlist.push_back(rhlist[j]); j++;}

		// if right list only is out of bounds
		if(!iout && jout) { newlist.push_back(lhlist[i]); i++;}

		// recheck boundaries
		iout = i>=lhlist.size();
		jout = j>=rhlist.size();

	}

	// return the newly constructed sorted list
	return newlist;
}



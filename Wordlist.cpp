/*
 * Wordlist.cpp
 *
 *  Created on: Feb 4, 2015
 *      Author: Alex, Thurston
 */

#include "heap.h"
#include "Wordlist.h"
#include "binarySearch.h"
#include "d_except.h"
#include "mergeSort.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdexcept>
#include <exception>
using namespace std;

// initialize to an empty list
Wordlist::Wordlist()
{ wds.resize(0); cout<<"hi\n";
  wdsHs.setHashTableSize(10000); cout<<"wut?\n";
  dataType = 0;
  longWordLength=0;}

// initialize with a file
Wordlist::Wordlist(string filename)
{ readWords(filename); }

void Wordlist::sortList(int opt)
{
	try{
		switch(opt)
		{
			case 4: { Heap hp(wds); hp.maxHeapSort(); wds = hp.getData(); break; }
			case 2:	wds = mergeSort<string>(wds,0,wds.size()-1); break;
			case 1: quickSort<string>(wds,0,wds.size()-1); break;
			default: insertionSort<string>(wds); break;
		}
	}
	catch(invalid_argument &e)
	{ cout << "In 'Wordlist' method 'sortList': invalid argument:\n" << e.what() << endl; }
	catch(exception &e) { cout << "In 'Wordlist' method 'sortList': unspecified exception:\n" << e.what() << endl; }
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
		// while loop runs as long as not at the end of the file
		while(!myFile.eof())
		{
			// enter a line into the temporary variable and then add it to the list
			wds.push_back((getline(myFile,temp),temp));
		}
		//close the file once all the words have been transfered into the data member wds.
		myFile.close();
	}
	//catch statement sees if an error is thrown whether the file can be read or not
	catch(ifstream::failure &e)
	{
		cout <<  "In 'Wordlist' method 'readWords': Error opening/reading file:\n" << e.what();
	}
	catch(exception &e) { cout << "In 'Wordlist' method 'readWords':\n" << e.what() << endl; }
}
//set the data type member data, so that the class knows which data type to deal with
void Wordlist::setDataType(int newDataType)
{
	dataType = newDataType;
}
//return the current data type of the word list
int Wordlist::getDataType()
{
	return dataType;
}
void Wordlist::readWordsHash(string filename)
{
	string temp;
	string word1;

	//open myFile which is the file inputed and creates an instream for that file
	ifstream myFile(filename.c_str());

	//tests the ability to open the file, if the file is able to be opened, then it starts storing the data
	//otherwise it throws an exception
	myFile.exceptions (ifstream::failbit | ifstream::badbit);
	try
	{
		// while loop runs as long as not at the end of the file
		while(!myFile.eof())
		{
			word1 = (getline(myFile,temp),temp);
			if(word1.length() > longWordLength)
			{
				longWordLength = word1.length();
			}
			if(word1.length() >= 5)
			{
				cout << "Working?" << endl;
				wdsHs.insertItem(word1);
			}
			//cout << word1 << endl;
		}
		//close the file once all the words have been transfered into the data member wds.
		myFile.close();
	}
	//catch statement sees if an error is thrown whether the file can be read or not
	catch(ifstream::failure &e)
	{
		cout <<  "In 'Wordlist' method 'readWords': Error opening/reading file:\n" << e.what();
		cout << "The location " << word1 << endl;
	}
	catch(exception &e) { cout << "In 'Wordlist' method 'readWords':\n" << e.what() << endl; }
	//wdsHs.printHistogram();
	//wdsHs.largestList();

}
//returns whether the current word is longer then any of the words in the wordlist
bool Wordlist::validLength(string word)
{
	return word.length() < longWordLength;
}

/**
 * getVectorSize() returns the current size of its data member wds.
 * In otherwords, it returns the number of current words in the Wordlist
 *
 * @ return -returns the size of the data member wds
 */

int Wordlist::getVectorSize() { return wds.size(); }
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
	{ cout << "In 'Wordlist' method 'getWord': Out of Range Error retrieving word from wordlist:\n" << oor.what();}
	return "";
}
/**
 *  compareWord uses a binary search to serach for a word in the word list and returns true
 *  if the inputed word matches a word in the list
 *
 *  @param string word -an inputed word that is compared against the word list to see if there is a matching word
 *  @return boolean, -returns true if there is a matching word, returns false if there is no matching word
 */
bool Wordlist::existWord(string wordTarget)
{
	if(dataType==1)
	{
		try { return wdsHs.getItemByKey(wordTarget); }
		catch(...) { cout << "in 'existWord': unable to check word"; }
	}
	if(dataType==0)
	{
		// search for a matching word in the wordlist
		try { return binSearch(wds,wordTarget,0,wds.size()-1,stringEqual); }

		// report invalid argument errors
		catch(invalid_argument &e)
		{ cout << "In 'Wordlist' method 'existWord: invalid argument:\n" << e.what() << endl; }

		catch(exception &e) { cout << "In 'Wordlist' method 'existWord: unspecified exception:\n " << e.what() << endl; }

		return false;
	}
	return false;
}

unsigned int Wordlist::getLongWordLength() {return longWordLength;}
/**
 * prefix: searches for whether the given word is a prefix for any word in the wordlist
 * @param string bj - a string to check if it is a prefix
 */
bool Wordlist::prefix(string bj)
{
	if(dataType==0)
	{
		try { return binSearch(wds,bj,0,wds.size()-1,stringPrefix); }

		catch(invalid_argument &e)
		{ cout << "In 'Wordlist' method 'prefix': invalid argument:\n" << e.what() << endl; }

		catch(exception &e)
		{ cout << "In 'Wordlist' method 'prefix': unspecified exception:\n" << e.what() << endl; }

		return false;
	}
	return false;
}
/**
 * getVector() returns the vector which contains a list of words
 * @return vector <string> -returns the vector that contains the word list
 */
vector <string> Wordlist::getVector() {
	try{return wds;}
    catch(const out_of_range& oor)
	{ cout << "In 'Wordlist' method 'getVector': out of range:\n" << oor.what(); return wds;}}

//overloading operator for << that prints out all the words stored in the wordlist, aka 'wds' vector
//this function returns an ostream with the string containing all the words
ostream& operator<< (ostream &ostr, Wordlist w1)
{
	//declare temporary string
	string temp = "";

	//appends each word to the temp string variable so that all the words are
	//stored in one string
	for(int i=0;i<w1.getVectorSize();i++)
	{ temp.append(w1.getWord(i)); temp.append("\n"); }

	//return the ostr with the temp string
	return ostr << temp;
}
Wordlist::~Wordlist() {
	// TODO Auto-generated destructor stub
}

// Sorts a vector of values using the insertion sort algorithm
template <typename T> void insertionSort(std::vector<T> &arr)
{
	// for indexing the array
	int j=0;

	// for temporary value storage
	T temp;

	/// sort from beginning to end
	for(int i=1; i < arr.size(); i++)
	{
		// pull out a value from unsorted part of the array
		temp=arr[i];

		j=i; // start searching at previous value

		// swap values over until the correct place is found
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

// sorts a vector of values using a quick sort algorithm
template <typename T> void quickSort(vector <T>& list, int left, int right)
{
	if((left < 0) || (right >= list.size()))
	{ throw invalid_argument("In quickSort': invalid argument\n"); }

	if(left < right)
	{
		int s = partition <T> (list, left, right);
		quickSort <T> (list, left, s-1);
		quickSort <T> (list, s+1, right);
	}

	return;
}

// partitions a sub vector into values beneath a pivot, and values above the pivot
template <typename T> int partition(vector <T>& list, int left, int right)
{
	if((left < 0) || (right >= list.size()))
	{ throw invalid_argument("In 'partition': invalid argument\n"); }

	//set the pivot to the middle element of the list
	int pivotindex = (left + right)/2;

	T pivot = list[pivotindex];

	// put the pivot value at the end of the sub array
	T temp = list[pivotindex]; list[pivotindex]=list[right]; list[right]=temp;

	//set i and lessindex as the left most element, so the beginning of the sublist
	int i = left, lessindex = left;

	// go through the list and move all values beneath the pivot to a lower index
	// keep track of the lesser value indices
	for(i=left;i<right;i++)
	{
		// swap values less than the pivot to the left of the 'lessindex'
		if(list[i] <= pivot)
		{
			temp           = list[i];
			list[i]        = list[lessindex];
			list[lessindex]= temp;
			lessindex++;
		}
	}

	// return the pivot to it's place
	temp           = list[lessindex];
	list[lessindex]= list[right];
	list[right]    = temp;

	// return the index used to sort to the to sides
	return lessindex;
}

// sorts a vector of values using the merge sort algorithm
template <typename T> vector<T> mergeSort(vector <T>& list, int left, int right)
{
	if((left < 0) || (right >= list.size()))
	{ throw invalid_argument("In 'mergeSort': invalid argument\n"); }

	// new list to add values
	vector<T> newlist;

	// base case: if given range of 1, push the single item into the list
	if(right==left) { newlist.push_back(list[right]); }

	// check for base case: length of list is invalid: array is sorted as a single object or empty
	if((right-left)<=0) {return newlist;}

	/* break the array into two (~equal) parts and sort them */

	int center = (right+left)/2;
	vector<T> lhlist = mergeSort(list,left,center);
	vector<T> rhlist = mergeSort(list,center+1,right);

	/* merge the two sorted pieces */
	int i=0, j=0; bool iout=false, jout=false;

	// check 'i' and 'j' boundaries, and quit when both indices are out of bounds
	while(( ( iout = i >= lhlist.size() ), ( jout = j >= rhlist.size() ), ( !iout || !jout ) ))
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
	}

	// return the newly constructed sorted list
	return newlist;
}



/*
 * Wordlist.cpp
 *
 *  Created on: Feb 4, 2015
 *      Author: Alex, Thurston
 */

#include "Wordlist.h"
#include "binarySearch.h"
#include "d_execpt.h"
#include "mergeSort.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdexcept>
#include <exception>
#include <vector>
using namespace std;

/*
 * heap.h
 *
 *  Created on: Feb 22, 2015
 *      Author: Thurston, ALex
 */
// do nothing default constructor
template <class T>
Heap<T>::Heap() {
	structuredheapsize=0;
	// TODO Auto-generated constructor stub
}

// inputs and initializes data to a maximum root heap
template <class T>
Heap<T>::Heap(vector<T> input) {
	initializeMaxHeap(input);
	buildMaxHeap();
	return;
}

// builds a maximum root heap from an unstructured array
/* in the future, this should just call 'buildHeap' */
template <class T>
void Heap<T>::buildMaxHeap() // turns a heap structure into a valid heap
{
	/*
	 - initialize heap structure size to full array of data
	 - move from last index with children to first index creating valid heaps
	 */
	structuredheapsize= data.size();
	if (!data.size()) {
		return;
	} // empty heap base case
	for (int i = (data.size()-1)/2; i >= 0; i--) {
		maxHeapify(i);
	}
	return;
}

// creates a maximum root heap of root i
/* in the future, this should just call 'heapify' */
template <class T>
void Heap<T>::maxHeapify(int i) // makes a heap with root i valid
{
	if (i < 0) {
		throw invalid_argument("In 'maxHeapify': invalid index\n");
	}
	int l = left(i), r = right(i); // left, right index: valid if >= 0
	string big = data[i];
	int ibig = i; // largest value and coresponding index: defaults to root

	if ((r >= 0) && (data[r] > big)) {
		big = data[r];
		ibig = r;
	} // check if index is valid first
	if ((l >= 0) && (data[l] > big)) {
		big = data[l];
		ibig = l;
	} // then find largest node/node-index

	// if the root isn't the largest, swap values, validate the swapped subheap
	if (ibig != i) {
		dataSwap(i, ibig);
		maxHeapify(ibig);
	}
	return;
}

/* in the future, this should call 'heapSort' */
template <class T>
void Heap<T>::maxHeapSort() {
	/*
	 - initialize heap structure size to full array of data & ensure we start with a fully valid heap
	 - then, move through the array from back to front creating a list from the back of the heap
	 - for each iteration: move top item to the back of the list and decrement the size of the array that is
	 considered part of the heap structure: this affects the 'left', 'right' functions
	 - then, recreate a valid heap
	 */
	structuredheapsize = data.size()-1;
	buildMaxHeap();
	for (int i = data.size()-1; i > 1; i--)
	{
		dataSwap(0, i);
		structuredheapsize -= 1;
		maxHeapify(0);
	}
	return;
}
/**
 * minHeapSort() sorts the heap vector from smallest to largest
 *
 */
template <class T>
void Heap<T>::minHeapSort()
{
	structuredheapsize = data.size()-1;
	buildMinHeap();
	for (int i = data.size()-1; i > 1; i--)
	{
		dataSwap(0, i);
		structuredheapsize -= 1;
		minHeapify(0);
	}
	return;
}
/**
 * minHeapfiy verifies and creates the heap structure
 * In this case it makes it a minHeap so that the node is smaller then
 * its children. This will be called recursively to fix broken heap structures
 * @param int i-the current node that is going to be fixed
 */
template <class T>
void Heap<T>::minHeapify(int i)
{
	if (i < 0) {
		throw invalid_argument("In 'maxHeapify': invalid index\n");
	}
	int l = left(i), r = right(i); // left, right index: valid if >= 0
	string small = data[i];
	int iSmall = i; // largest value and coresponding index: defaults to root

	if ((r >= 0) && (data[r] < small)) {
		small = data[r];
		iSmall = r;
	} // check if index is valid first
	if ((l >= 0) && (data[l] < small)) {
		small = data[l];
		iSmall = l;
	} // then find largest node/node-index

	// if the root isn't the largest, swap values, validate the swapped subheap
	if (iSmall != i) {
		dataSwap(i, iSmall);
		minHeapify(iSmall);
	}
	return;
}
/**
 * buildMinHeap takes a random vector of type T and turns
 * it into a minHeap structure
 */
template <class T>
void Heap<T>::buildMinHeap()
{
	/*
	 - initialize heap structure size to full array of data
	 - move from last index with children to first index creating valid heaps
	 */
	structuredheapsize= data.size()-1;
	if (!data.size()) {
		return;
	} // empty heap base case
	for (int i = (data.size()-1)/2; i >= 0; i--) {
		minHeapify(i);
	}
	return;
}

// swap values of data
template <class T>
void Heap<T>::dataSwap(int i, int j) {
	if (i >= data.size() || j >= data.size() || i < 0 || j < 0) // check indexing boundaries
			{
		throw out_of_range("In 'dataSwap': index out of bounds");
	}
	string temp = data[i];
	data[i] = data[j];
	data[j] = temp;
	return;
}

template <class T>
Heap<T>::~Heap() {
	// TODO Auto-generated destructor stub
}

/*
 * HashTable.cpp
 *
 *  Created on: Feb 15, 2015
 *      Author: Alex, Thurston
 */

using namespace std;
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>

template <class T>
HashTable <T> ::HashTable(int tableLength) {
	// TODO Auto-generated constructor stub
	if(tableLength <= 0){throw invalid_argument("In 'mergeSort': invalid argument\n");}
	hashObject.resize(tableLength);
	length = tableLength;

}
template <class T>
void HashTable<T>::setHashTableSize(int tableLength)
{
	if(tableLength <= 0) {throw invalid_argument("In 'mergeSort': invalid argument\n");}
	hashObject.resize(tableLength);
	length = tableLength;
}
// returns the location of the word in the hashtable
template <class T>
int HashTable<T>::hash( T itemKey)
{
	int result=1;
	for(int i=0; i<3;i++)
	{
		//if the character at that spot is a a-z then find its ascii value subtracted
		//by 95 to put it into the range of 1-27 to reduce the size of the hash table
		if((int)itemKey[i] >=97 && (int)itemKey[i] <= 122)
		{
			result *= (int)itemKey[i]-95;
		}
		//if the character is not a-z then arbitrary give that character
		//the value of 24
		else
		{
			result *= 24;
		}
	}
	//add some more elements to the hash to make it more unique
	result += (int)itemKey[1];
	result += (int)itemKey[2];
	result += (int)itemKey[3];
	result -= (int)itemKey[4];
	result = result % 10000;
	//return the result which is the location of the word
	return result;

}

// find the largest linked list and prints out its size
template <class T>
void HashTable<T>::largestList()
{
	//sets the initalize size to the first element
	T largestListIndex = hashObject[0].size();
	int largestListIndexLocation=0;
	//loops through every link list created
	for(int i=1; i<length;i++)
	{
		//if the size of the list is bigger then the biggest list
		//then set that link list as the biggest list
		if(hashObject[i].size()> largestListIndex)
		{
			largestListIndex = hashObject[i].size();
			largestListIndexLocation = i;
		}
	}
	//print out the result of the search
	cout << "The largest size is " << largestListIndex << endl;
	cout << "The location of this is " << largestListIndexLocation << endl;
}

//Add an item to the hash table
template <class T>
void HashTable<T>::insertItem(T itemKey)
{
	//find the location for the given key
	int location = hash(itemKey);
	//insert the element to the back of the vector
	hashObject[location].push_back(itemKey);

}
// Returns an item from the Hash Table by key.
// If item not found, false returned
template <class T>
bool HashTable<T>::getItemByKey(T itemKey)
{
	//finds the location that the item would be at
	int location = hash(itemKey);
	//searches all the chained elements at that hash location
	for(int i=0; i< hashObject[location].size();i++)
	{
		//if the same exact key is found then return true
		//else return false
		if(itemKey == hashObject[location].at(i))
		{
			return true;
		}
	}
	return false;

}

// Prints a histogram showing Item distribution
template <class T>
void HashTable<T>::printHistogram()
{
	cout << "\n\nHash table Contains ";
	cout << getNumberOfItems() << " Items total." << endl;
	//Iterates for every item in the Hash Table
	for(int i=0;i<length;i++)
	{
		cout << i+1 << ":\t";
		//iterates through the chaining elements in each location of the hash table
		//prints out an X for each element in that location as to indicate
		//one element per X
		for(int j=0;j<hashObject[i].size();j++)
		{
			cout << " X";
		}
		cout << endl;
	}

}

// Return the number of Items in a location
template <class T>
int HashTable<T>::getLength()
{
	//returns the length of the hashTable
	return length;
}

// Returns the number of Items in the HashTable
template <class T>
int HashTable<T>::getNumberOfItems()
{
	int totalNum;
	//iterates through every element in the hash table and
	//adds up all the chaining elements at each location
	//to find the total amount of elements currently in the hash table
	for(int i=0; i<length;i++)
	{
		totalNum += hashObject[i].size();
	}
	return totalNum;
}
template <class T>
HashTable<T>::~HashTable() {
	// TODO Auto-generated destructor stub
}


// initialize to an empty list
Wordlist::Wordlist()
{
	try
	{
		wds.resize(0);
		wdsHs.setHashTableSize(10000);
		dataType = 0;
		longWordLength=0;
	}
	catch(invalid_argument &e)
	{ cout << "In WordList constructor : " << e.what() << endl; }
	catch(exception &e)
	{ cout << "In 'Wordlist' method 'constructor': unspecified exception:\n" << e.what() << endl; }
}

// initialize with a file
Wordlist::Wordlist(string filename)
{ readWords(filename); }

void Wordlist::sortList(int opt)
{
	if(opt > 4)
	{ throw invalid_argument ("The argument is not within the range 1-4, the default value of insertion sort is going to be called");
	}
	try{
		switch(opt)
		{
			// case for heap sort
			case 4:
			{
				//Temporarily constructs a Heap Sort data structure.
				//The wds list is entered into the heap structure and buildMaxHeap
				//and maxHeapify is called to make the new vector a valid heap structure
				Heap <string> hp(wds);
				//calls max HeapSort on the list of words to sort the vector
				//from largest to smallest
				hp.maxHeapSort();
				//returns the internal list of the heap class into the wds class
				wds = hp.getData();
				break;
			}
			//calls merge sort to sort the list of words
			case 2:	wds = mergeSort<string>(wds,0,wds.size()-1); break;
			//calls quicksort to sort the vector
			case 1: quickSort<string>(wds,0,wds.size()-1); break;
			//calls insertion sort to sort the words
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
			//put the word from each line into the variable word1 so that it
			//can be stored into the hash table
			word1 = (getline(myFile,temp),temp);
			//stores the longest word found in the data member function
			// this is used instead of prefixes to terminate searching a row
			//if it is bigger then all possible words in the wordlist
			if(word1.length() > longWordLength)
			{
				longWordLength = word1.length();
			}
			//only adds a word to the hash table if the total number of letters is greater
			//then 5 to limit the amount of words in the hash table
			if(word1.length() >= 5)
			{
				wdsHs.insertItem(word1);
			}
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




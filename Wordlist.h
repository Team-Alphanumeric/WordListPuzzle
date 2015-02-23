/*
 * Wordlist.h
 *
 *  Created on: Feb 4, 2015
 *      Author: Alex, Thurston
 */

#ifndef WORDLIST_H_
#define WORDLIST_H_
#include <iostream>
using namespace std;
#include <vector>
#include "insertionSort.h"
#include "quickSort.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdexcept>
#include <exception>
using namespace std;



// make heap a vector with expanded data & functionality
template <class T>
class Heap {
public:
	Heap(); // useless: utterly unequivocally unimportant. ugh.
	Heap(vector<T> input); // creates a max heap
	int parent(int i) {	return (i > 0) ? ((i - 1) / 2) : -1; } // gets the index of the parent: returns -1 for bastards
	int left(int i) { int a = (2 * (i + 1) - 1); return ((a < structuredheapsize) ? a : -1); } // gets the index of the left heap: -1 for non existent heaps
	int right(int i) { int a = (2 * (i + 1)); return ((a < structuredheapsize) ? a : -1); } // get the index of the right heap: -1 for non existent heaps
	string getItem(int i) {return data[i];} // gets the T(hing) at the index
	void setItem(int i, string gj) {	data[i] = gj; } // sets the T(hing) at the index
	void initializeMaxHeap(vector<string> input) { data = input; } // inputs a vector of T(hings)
	vector<string> getData() { return data; }
	int getHeapSize() {	return structuredheapsize; } // get the heap size
	void setHeapSize(int n) { structuredheapsize = n;	} // set the heap size
	int size() { return data.size(); } // get the vector size
	void buildMaxHeap(); // turns a heap structure into a valid maximum root heap
	void maxHeapify(int i); // makes a heap a valid maximum root heap
	void maxHeapSort();
	void minHeapSort();
	void minHeapify(int i);
	void buildMinHeap();
	void dataSwap(int i, int j);
	virtual ~Heap();
protected:
	vector<string> data;
	int structuredheapsize;
};


/*
 * HashTable.h
 *
 *  Created on: Feb 15, 2015
 *      Author: alex
 */
#include <vector>
template <class T>
class HashTable {
public:
	//construct an empty Hash table object
	//Sets the default array size to 15
	HashTable(int tableLength=15);\

	//set the size of the hashtable
	void setHashTableSize(int tableLength=15);

	//Add an item to the hash table
	void insertItem(T word);

	//Delete an Item from the Hash Table
	// Returns true if the operation is successful
	bool deleteItem(T itemKey);

	// Returns an item from the Hash Table by key.
	// If item not found, Null Pointer returned
	bool getItemByKey(T itemKey);

	// Display the contents of the Hash Table to console window
	void printHashTable();

	// Prints a histogram showing Item distribution
	void printHistogram();

	//find the largest list
	void largestList();

	// Return the number of Items in a location
	int getLength();

	// Returns the number of Items in the HashTable
	int getNumberOfItems();

	// De-allocates all memory used for the Hash Table
	virtual ~HashTable();
private:
	//reference to an array of type LinkList
	vector <vector <string> > hashObject;

	//length of the hash table
	int length;

	//returns an array location for a given item key
	int hash( T itemKey);

};

class Wordlist {
private:
	unsigned int longWordLength;
protected:
	vector <string> wds;
	HashTable <string> wdsHs;
	int dataType;
public:
	Wordlist();
	Wordlist(string filename);
	void readWords(string filename);
	void setDataType(int newDataType);
	int getDataType();
	bool validLength(string word);
	void readWordsHash(string filename);
	void printWords();
	int getVectorSize();
	bool binSearchWordList(vector <string> wordlist, string wordTarget);
	vector <string> getVector();
	bool existWord(string word1);
	bool prefix(string word1);
	void sortList(int opt=0);
	string getWord(const int index);
	unsigned int getLongWordLength();
	friend ostream& operator<< (ostream &ostr, Wordlist w1);
	virtual ~Wordlist();
};

#endif /* WORDLIST_H_ */

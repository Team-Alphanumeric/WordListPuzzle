/*
 * HashTable.cpp
 *
 *  Created on: Feb 15, 2015
 *      Author: alex
 */

#include "HashTable.h"
using namespace std;
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>


HashTable::HashTable(int tableLength) {
	// TODO Auto-generated constructor stub
	if(tableLength <= 0) tableLength = 15;
	array = new LinkList[ tableLength ];
	length = tableLength;

}

void HashTable::setHashTableSize(int tableLength)
{
	if(tableLength <= 0) tableLength =15;
	array = new LinkList[ tableLength ];
	length = tableLength;
}
// returns the location of the word in the hashtable
int HashTable::hash( string itemKey)
{
	int result=1;
	for(int i=0; i<3;i++)
	{
		//cout << "the character " << itemKey[i] << endl;
		//cout << "resut" << result << endl;
		if((int)itemKey[i] >=97 && (int)itemKey[i] <= 122)
		{
			result *= (int)itemKey[i]-95;
		}
		else
		{
			result *= 24;
		}
		//cout << "test spot ";
	}
	cout << "Word " << itemKey << endl;
	result += (int)itemKey[1];
	result += (int)itemKey[2];
	//result += (int)itemKey[3];
	//result -= (int)itemKey[4];
	result = result % 2000;
	cout << "result " << result << endl;
	return result;

}

// find the largest linked list and prints out its size
void HashTable::largestList()
{
	int largestListIndex = array[0].getLength();
	int largestListIndexLocation=0;
	//loops through every link list created
	for(int i=1; i<length;i++)
	{
		//if the size of the list is bigger then the biggest list
		//then set that link list as the biggest list
		if(array[i].getLength()> largestListIndex)
		{
			largestListIndex = array[i].getLength();
			largestListIndexLocation = i;
		}
	}
	//cout << "The largest size is " << largestListIndex << endl;
	//cout << "The location of this is " << largestListIndexLocation << endl;
}

//Add an item to the hash table
void HashTable::insertItem(string word)
{
	int location = hash(word);
	cout << "Location " << location << endl;
	array[location].printList();
	cout << "Another test" << endl;
	array[location].insertItem(word);
	//array[location].printList();
}

//Delete an Item from the Hash Table
// Returns true if the operation is successful
bool HashTable::deleteItem(string itemKey)
{
	int location = hash(itemKey);
	return array[location].removeItem(itemKey);

}

// Returns an item from the Hash Table by key.
// If item not found, Null Pointer returned
bool HashTable::getItemByKey(string itemKey)
{
	int location = hash(itemKey);
	return (array[location].getItem(itemKey) != NULL);
}

// Display the contents of the Hash Table to console window
void HashTable::printHashTable()
{
	cout << "The hash Table contents are " << endl;
	for(int i=0;i<length;i++)
	{
		cout << "In location " << i + 1 << ": ";
		array[i].printList();
		cout << "test" << endl;
	}
}

// Prints a histogram showing Item distribution
void HashTable::printHistogram()
{
	cout << "\n\nHash table Contains ";
	cout << getNumberOfItems() << " Items total." << endl;
	for(int i=0;i<(length-11000);i++)
	{
		cout << i+1 << ":\t";
		for(int j=0;j<array[i].getLength();j++)
		{
			cout << " X";
		}
		cout << endl;
	}

}

// Return the number of Items in a location
int HashTable::getLength()
{
	return length;
}

// Returns the number of Items in the HashTable
int HashTable::getNumberOfItems()
{
	int totalNum;
	for(int i=0; i<length;i++)
	{
		totalNum += array[i].getLength();
	}
	return totalNum;
}

HashTable::~HashTable() {
	// TODO Auto-generated destructor stub
}


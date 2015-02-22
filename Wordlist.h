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
#include "HashTable.h"

class Wordlist {
private:
	unsigned int longWordLength;
protected:
	vector <string> wds;
	HashTable wdsHs;
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

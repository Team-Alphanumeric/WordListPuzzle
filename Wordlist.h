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

class Wordlist {
protected:
	vector <string> wds;
public:
	Wordlist();
	Wordlist(string filename);
	void readWords(string filename);
	void printWords();
	int getVectorSize();
	bool binSearchWordList(vector <string> wordlist, string wordTarget);
	vector <string> getVector();
	bool existWord(string word1);
	bool prefix(string word1);
	void sortList(int opt=0);
	string getWord(const int index);
	friend ostream& operator<< (ostream &ostr, Wordlist w1);
	virtual ~Wordlist();
};

#endif /* WORDLIST_H_ */

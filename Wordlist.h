/*
 * Wordlist.h
 *
 *  Created on: Feb 4, 2015
 *      Author: alex
 */

#ifndef WORDLIST_H_
#define WORDLIST_H_
#include <iostream>
using namespace std;
#include <vector>

class Wordlist {
protected:
	vector <string> wds;
public:
	Wordlist();
	void readWords(string filename);
	void printWords();
	int getVectorSize();
	bool binSearchWordList(vector <string> wordlist, string wordTarget);
	vector <string> getVector();
	bool compareWord(string word1);
	string getWord(const int index);
	friend ostream& operator << (ostream &ostr, Wordlist w1);
	virtual ~Wordlist();
};

#endif /* WORDLIST_H_ */

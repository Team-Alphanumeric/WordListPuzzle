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
	vector <string> getVector();
	template <typename T>
	void quickSort(const vector <T> list, int left, int right);
	void quiSort();
	template <typename T>
	int partition(const vector <T> list, int left, int right);
	string getWord(const int index);
	friend ostream& operator << (ostream &ostr, Wordlist w1);
	friend bool operator< (const string lhs, string rhs);
	virtual ~Wordlist();
};

#endif /* WORDLIST_H_ */

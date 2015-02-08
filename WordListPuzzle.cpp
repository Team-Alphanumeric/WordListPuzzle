//============================================================================
// Name        : WordListPuzzle.cpp
// Author      : Alex Agudelo, Thurston Brevett
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Wordlist.h"

int main(void)
{
	Wordlist w1;
	string temp;
	w1.readWords("wordList.txt");
	cout << w1;
	return 0;
}

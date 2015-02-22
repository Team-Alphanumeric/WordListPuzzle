/*
 * LinkList.h
 *
 *  Created on: Feb 15, 2015
 *      Author: alex
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

#include <iostream>
#include <string>
using namespace std;

//creates a structure of sName
struct sName
{
	string key;
	sName *pNext;
};

class LinkList {
private:
	sName *head;
	int length;
public:
	LinkList();
	void insertItem (string newWord);
	bool removeItem (string itemKey);
	sName * getItem (string itemKey);
	void printList();
	int getLength();
	virtual ~LinkList();
};

#endif /* LINKLIST_H_ */

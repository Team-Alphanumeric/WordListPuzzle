/*
 * LinkList.cpp
 *
 *  Created on: Feb 15, 2015
 *      Author: alex
 */

#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>

LinkList::LinkList() {
	head = new sName;
	head -> pNext = NULL;
	length = 0;
}
void  LinkList::insertItem(string newWord) {
	sName * newItem = new sName;
	newItem -> key = newWord;
	if(!(head->pNext)) {
		head -> pNext = newItem;
		length++; return;
	}
	else
	{
		sName * conductor; sName * nextList;
		conductor = head; nextList = head;
		cout << "test" << endl;
		while(conductor -> pNext != NULL)
		{
			//nextList = conductor;
			//conductor = nextList ->pNext;
			conductor = conductor ->pNext;
			cout << "test2" << endl;
			cout << "conductor pointer " << conductor << endl;
			cout << "next conductor pointer " << conductor -> pNext << endl;
		}
		conductor -> pNext = newItem; newItem -> pNext = NULL;
		length++;
	}

}
bool LinkList::removeItem (string itemKey)
{
	if(!(head->pNext))
	{ return false;	}
	else {
		sName * conductor = head;
		sName *nextList =head;
		while(conductor)
		{
			if(conductor -> key == itemKey)
			{
				nextList -> pNext = conductor -> pNext;
				delete conductor;
				length--;
				return true;
			}
			nextList = conductor;
			conductor = nextList ->pNext;
		}
	}
	return false;
}
sName * LinkList::getItem (string itemKey)
{
	sName * conductor = head;
	sName * nextList = head;
	while(conductor)
	{
		if((conductor != head) && (conductor -> key == itemKey))
		{
			return conductor;
		}
		nextList = conductor;
		conductor = nextList -> pNext;
	}
	return NULL;
}
void LinkList::printList()
{
	sName * conductor = head;
	sName * nextList = head;
	if(length==0)
	{
		cout << "Empty List" << endl;
		return;
	}
	cout << "Head --> ";
	while(conductor)
	{
		if(conductor != head)
		{
			cout << conductor -> key;
			if(conductor -> pNext)
			{
				cout << " --> ";
			}
			else
			{
			}
		}
		nextList = conductor;
		conductor = nextList -> pNext;
	}
	cout << endl;
	//cout << "test2" << endl;
}
int LinkList::getLength()
{
	return length;
}
LinkList::~LinkList() {
	// TODO Auto-generated destructor stub
}


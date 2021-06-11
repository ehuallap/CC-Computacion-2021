#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>
#include "Node.h"

class LinkedList;

std::ostream& operator<<(std::ostream& out, LinkedList l);

class LinkedList
{
private:
	int size;
	Node* head;
public:
	LinkedList();
	LinkedList(Node _head);
	LinkedList(const LinkedList& o);
	void insert(Node _nuevo);
	void remove(int pos);

	int getSize();

	friend std::ostream& operator<<(std::ostream& out, LinkedList l);
	~LinkedList();
};

#endif
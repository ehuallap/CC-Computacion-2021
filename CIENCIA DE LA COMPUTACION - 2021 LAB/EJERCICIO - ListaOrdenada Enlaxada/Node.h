#ifndef __NODE_H__
#define __NODE_H__
# include <iostream>
class Node
{
private:
	int element;
	Node* next;
public:
	Node();
	Node(int _elemento);
	Node(const Node& a);
	void setElement(int _nuevoElem);
	void setNext(Node &_next);
	int getElement();
	Node* getNext();
	~Node();
};

#endif
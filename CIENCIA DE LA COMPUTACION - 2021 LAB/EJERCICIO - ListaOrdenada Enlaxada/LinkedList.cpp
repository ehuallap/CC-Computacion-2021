#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
	this->size = 0;
	this->head = nullptr;
}

LinkedList::LinkedList(Node _head) {
	this->head = &_head;
	this->size = 1;
}

LinkedList::LinkedList(const LinkedList& o) {
	this->head = o.head;
	this->size = o.size;
}

void LinkedList::insert(Node _nuevo) {
	int nuevoValue = _nuevo.getElement();
	int controlValue = head->getElement();
	if (controlValue < nuevoValue) {
		if (size > 1) {
			Node* mayor = head->getNext();
			Node* menor = head;
			while (mayor->getNext() != nullptr) {
				if (mayor->getElement() >= nuevoValue) {
					menor->setNext(_nuevo);
					_nuevo.setNext(*mayor);
					break;
				}
				else {
					mayor = mayor->getNext();
					menor = menor->getNext();
				}
			}
			if (mayor->getNext() == nullptr) {
				mayor->setNext(_nuevo);
			}
		}
		else{
			head->setNext(_nuevo);
		}
	}else {
		_nuevo.setNext(*head);
		head = &_nuevo;
	}
	size += 1;
}
void LinkedList::remove(int pos) {
	Node* mayor = this->head->getNext();
	Node* menor = this->head;
	if (pos == 0) {
		this->head = mayor;
		//delete &menor;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (i == pos - 1) {
				menor->setNext(*mayor->getNext());
				//delete &mayor;
			}
			else {
				mayor = mayor->getNext();
				menor = menor->getNext();
			}
		}
	}
	size -= 1;
}
int LinkedList::getSize() {
	return size;
}

LinkedList::~LinkedList() {
}

std::ostream& operator<<(std::ostream& out, LinkedList p) {
	Node* aux = p.head;
	for (int i = 0; i < p.getSize(); i++) {
		out << aux->getElement();
		if (i != p.getSize() - 1)
			out << " -> ";
		aux = aux->getNext();
	}
	return out;
}
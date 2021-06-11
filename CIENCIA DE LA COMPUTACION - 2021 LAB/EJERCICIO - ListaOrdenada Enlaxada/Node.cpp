#include "Node.h"
Node::Node() {
	this->element = 0;
	this->next = nullptr;
}
Node::Node(int _elemento = 0) {
	this->element = _elemento;
	this->next = nullptr;
}

Node::Node(const Node& a) {
	this->element = a.element;
	this->next = a.next;
}

void Node::setElement(int _nuevoElement) {
	this->element = _nuevoElement;
}

void Node::setNext(Node &_next) {
	this->next = &_next;
}

int Node::getElement() {
	return element;
}
Node* Node::getNext() {
	return next;
}
Node::~Node() {}
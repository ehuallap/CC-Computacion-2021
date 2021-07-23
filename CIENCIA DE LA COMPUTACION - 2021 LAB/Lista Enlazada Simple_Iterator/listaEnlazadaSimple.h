#ifndef __LISTA_ENLAZADA__
#define __LISTA_ENLAZADA__

#include <iostream>
#include "patronIterator.h"
using namespace std;

template <typename type>
class listaEnlazada {
	friend class patronIterator<type, listaEnlazada>;
private:
	unsigned int size;
	type* head;
public:
	//CONSTRUCTOR
	explicit listaEnlazada(type init_valor = type{}, unsigned int init_size = 1)
		: head(&init_valor), size(init_size) {}

	//DESTRUCTOR
	~listaEnlazada() {
		if (head == nullptr)
			delete[] head;
	}

	//COPY CONSTRUCTOR
	listaEnlazada(const listaEnlazada& second) : size(second.size), head(new type{ *second.head })
	{
		type* copiado = second.head;
		type* copiar = head;

		while (copiado->hasNext()) {
			copiar->setNext(*new type{ *copiado->getNext() });
			copiar = copiar->getNext();
			copiado = copiado->getNext();
		}
	}

	//MOVE CONSTRUCTOR
	listaEnlazada(listaEnlazada&& second) noexcept {
		head = nullptr;
		size = 0;

		head = second.head;
		size = second.size;

		type* copiado = second.head;
		type* copiar = head;

		while (copiado->hasNext()) {
			copiar->setNext(*copiado->getNext());
			copiar = copiar->getNext();
			copiado = copiado->getNext();
		}


		second.head = nullptr;
		second.size = 0;
	}

	//COPY ASSIGNMENT
	listaEnlazada& operator= (const listaEnlazada& second) {
		if (this != &second) {
			size = second.size;
			head = new type{ *second.head };

			type* copiado = second.head;
			type* copiar = head;

			while (copiado->hasNext()) {
				copiar->setNext(*new type{ *copiado->getNext() });
				copiar = copiar->getNext();
				copiado = copiado->getNext();
			}
		}
		return *this;
	}

	//MOVE ASSIGNMENT
	listaEnlazada& operator= (listaEnlazada&& second) noexcept {
		if (this != &second) {
			size = second.size;

			std::swap(head, second.head);

			type* copiado = second.head;
			type* copiar = head;

			while (copiado.hasNext()) {
				copiar->setNext(*copiado->getNext());
				copiar = copiar->getNext();
				copiado = copiado->getNext();
			}

			second.head = nullptr;
			second.size = 0;
		}
		return *this;
	}

	type* getHead() const {
		if (head != nullptr)
			return this->head;
	}

	unsigned int recountSize() const {
		type* pos = head;
		unsigned int new_size = 1;
		while (pos->hasNext())
		{
			new_size += 1;
			pos = pos->getNext();
		}
		return new_size;
	}

	unsigned int getSize() {
		size = this->recountSize();
		return size;
	}

	void setHead(type& x) {
		head = &x;
	}

	void pushBack(type& x){
		type* actual = head;
		while (actual->hasNext()) {
			actual = actual->getNext();
		}
		actual->setNext(x);
	}

	void pushFront(type& x) {
		x.setNext(*head);
		head = &x;
	}

	void insert(type& x, unsigned int pos) {
		if (pos == 0) {
			pushFront(x);
			return;
		}
		if (pos == size - 1) {
			pushBack(x);
			return;
		}
		if (pos >= size)
			return;
		type* actual = head;
		type* anterior = head;
		unsigned int pos_actual= 0;

		while (pos_actual != pos) {
			actual = actual->getNext();
			if (pos_actual != 0)
				anterior = anterior->getNext();
			pos_actual += 1;
		}
		x.setNext(*actual);
		anterior->setNext(x);
	}

	void popBack() {
		type* actual = head;
		while (actual->getNext()->hasNext()) {
			actual = actual->getNext();
		}
		actual->makeNextNull();
	}

	void popFront() {
		type* actual = head->getNext();
		head = actual;
	}

	void remove(unsigned int pos) {
		if (pos == 0) {
			popFront();
			return;
		}
		if (pos == size - 1) {
			popBack();
			return;
		}
		if (pos >= size)
			return;
		
		type* actual = head;
		type* anterior = head;
		unsigned int pos_actual = 0;

		while (pos_actual != pos) {
			actual = actual->getNext();
			if (pos_actual != 0)
				anterior = anterior->getNext();
			pos_actual += 1;
		}
		anterior->setNext(*actual->getNext());
		actual->makeNextNull();
	}

	//CONSTRUCTOR PARA CREAR ITERADOR DE ESA LISTA ENLAZADA SIMPLE
	patronIterator <type, listaEnlazada>* CreateIterator() {
		return new patronIterator<type, listaEnlazada>(this);
	}

};

#endif


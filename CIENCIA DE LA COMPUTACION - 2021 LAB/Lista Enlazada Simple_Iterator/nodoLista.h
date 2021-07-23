#ifndef __NODO_LISTA__
#define __NODO_LISTA__

#include <iostream>
using namespace std;

template <typename T>
class nodoLista {
	friend std::ostream& operator<<(std::ostream& out, const nodoLista<T>& nodoActual);
private:
	T value;
	nodoLista* next;
public:

	//CONSTRUCTOR
	explicit nodoLista(T init_value = NULL)
		: value(init_value), next(nullptr) {}

	//DESTRUCTOR
	~nodoLista() {
		if (next == nullptr)
			delete[] next;
	}

	//COPY CONSTRUCTOR
	nodoLista(const nodoLista& second){
		value = second.value;

		if (second.next != nullptr) {
			next = new nodoLista{ *second.next };
		}else
			next = nullptr;
	}

	//MOVE CONSTRUCTOR
	nodoLista(nodoLista&& second) noexcept {
		value = NULL;
		next = nullptr;

		value = second.value;
		next = new nodoLista{ *second.next };

		second.value = NULL;
		second.next = nullptr;
	}
	
	//COPY ASSIGNMENT
	nodoLista& operator= (const nodoLista& second) {
		if (this != &second) {

			value = second.value;
			next = second.next;
		}
		return *this;
	}

	//MOVE ASSIGNMENT
	nodoLista& operator= (nodoLista&& second) noexcept {
		if (this != &second) {

			std::swap(value, second.value);
			std::swap(next, second.next);
		}
		return *this;
	}
	void setValue(T nuevoValor) {
		value = nuevoValor;
	}

	void setNext( nodoLista& node_next) {
		next = &node_next;
	}

	void makeNextNull() {
		next = nullptr;
	}
	const T getValue() const {
		return value;
	}
	
	nodoLista* getNext() {
		if (next != nullptr)
			return this->next;
		else
			return nullptr;
	}

	const bool hasNext() {
		return (next != nullptr);
	}
	void literalHasNext() {
		if (!this->hasNext())
			cout << "...este es el final" << endl;
		else {
			cout << "..aun continua en " << *this->getNext() << endl;
		}
	}
};

std::ostream& operator<<(std::ostream& out, const nodoLista<int>& nodoActual) {
	out << "[ " << nodoActual.value << " ]";
	nodoLista<int>* temp = nodoActual.next;
	if (temp != nullptr)
		out << " -> ";
	return out;
}

#endif
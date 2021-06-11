#include "Node.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;


int main()
{
    Node nodo1(1); //[0]
    Node nodo2(2); //[1]
    Node nodo3(3); //[2]
    Node nodo4(5); //[3]
    Node nodo5(7); //[4]
    
    LinkedList listaEnlazada(nodo3);

    listaEnlazada.insert(nodo1);
    listaEnlazada.insert(nodo4);
    listaEnlazada.insert(nodo2);
    listaEnlazada.insert(nodo5);
    
    cout << "LISTA ENLAZADA CREADA: " << listaEnlazada << endl;

    listaEnlazada.remove(3);

    cout << "LISTA ENLAZADA MODIFICADA: " << listaEnlazada << endl;

    return 0;
}

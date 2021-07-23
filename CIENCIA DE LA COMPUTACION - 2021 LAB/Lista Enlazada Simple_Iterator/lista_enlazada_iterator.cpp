/*AUTOR: ERICK KLENDORT HUALLA PUELLES - ESTUDIANTE DE C. DE LA COMPUTACION*/

#include <iostream>
using namespace std;

#include "nodoLista.h"
#include "listaEnlazadaSimple.h"

int main()
{
    cout << "\nCREANDO 3 NODOS COPIADOS ENTRE SI PARA VERIFICAR USO DE LOS BIG-FIVE: " << endl;
    nodoLista<int> node_1{2};
    nodoLista<int> node_2 = node_1;
    nodoLista<int> node_3;
    node_3 = node_2;
    node_1.setValue(4);

    cout << "\nIMPRIENDO NODOS PARA VER FUNCIONAMIENTO DE BIG-FIVE: " << endl;
    cout << "NODO 1: " << node_1.getValue() << endl; //4
    cout << "NODO 2: " << node_2.getValue() << endl; //2
    cout << "NODO 3: " << node_3.getValue() << endl; //2
    
    cout << "\nCAMBIANDO VALORES DE LOS NODOS PARA MOSTRAR METODOS GETVALUE Y SOBRECARGA: " << endl;
    node_1.setValue(1);
    node_2.setValue(2);
    node_3.setValue(3);
    
    cout << "\nIMPRIENDO NODOS POR METODO GETVALUE(): " << endl;
    cout << "NODO 1: " << node_1.getValue() << endl; //4
    cout << "NODO 2: " << node_2.getValue() << endl; //2
    cout << "NODO 3: " << node_3.getValue() << endl; //2
    
    cout << "\nASIGNANDO NODOS 2 Y 3 COMO CONTIGUOS AL NODO 1... " << endl;
    node_1.setNext(node_2);
    node_2.setNext(node_3);
    
    cout << "\nCREANDO UNA COPIA PROFUNDA DE NODO 1 EN NODO 4: " << endl;
    nodoLista<int> node_4 = node_1;
    cout << "NODO 1: " << endl;
    node_1.literalHasNext();
    
    cout << "NODO 4: " << endl;
    node_4.literalHasNext();
    
    cout << "\nMODIFICANDO SEGUNDO NODO CONTIGUO EN NODOS 1 Y 4... " << endl;
    cout << "\nIMPRIMIENDO NODOS CONTIGUOS EN NODOS 1 Y 4 PARA DEMOSTRAR COPIA PROFUNDA: " << endl;
    cout << "ADEMAS SE ESTA UTILIZANDO LA SOBRECARGA DE OPERADOR << PARA IMPRIMIR NODOS" << endl;
    node_1.getNext()->setValue(9);
    node_4.getNext()->setValue(6);
    
    cout << node_1 << *node_1.getNext() << *node_1.getNext()->getNext() << endl; //1 9 3
    cout << node_4 << *node_4.getNext() << *node_4.getNext()->getNext() << endl; //1 6 3

    cout << "\nCREANDO 3 LISTAS COPIADAS ENTRE SI PARA VERIFICAR USO DE LOS BIG-FIVE: " << endl;
    listaEnlazada<nodoLista<int>> lista_1(node_1);

    listaEnlazada<nodoLista<int>> lista_1;

    listaEnlazada<nodoLista<int>> lista_2 = lista_1;
    listaEnlazada<nodoLista<int>> lista_3;
    lista_3 = lista_2;
    lista_1.setHead(node_4);
    
    cout << "\nIMPRIENDO SEGUNDOS NODOS DE LISTAS SIN ITERATOR: " << endl;
    cout << "LISTA 1 [ORIGINADA DE NODO 4]: " << *lista_1.getHead()->getNext() << " SIZE: " << lista_1.getSize() << endl;
    cout << "LISTA 2 [ORIGINADA DE NODO 1]: " << *lista_2.getHead()->getNext() << " SIZE: " << lista_2.getSize() << endl;
    cout << "LISTA 3 [ORIGINADA DE NODO 1]: " << *lista_3.getHead()->getNext() << " SIZE: " << lista_3.getSize() << endl;
    
    patronIterator<nodoLista<int>, listaEnlazada<nodoLista<int>>>* patronIt_1 = lista_1.CreateIterator();
    patronIterator<nodoLista<int>, listaEnlazada<nodoLista<int>>>* patronIt_2 = lista_2.CreateIterator();
    patronIterator<nodoLista<int>, listaEnlazada<nodoLista<int>>>* patronIt_3 = lista_3.CreateIterator();

    cout << "\nIMPRIENDO LISTAS ENLAZADAS CON PATRON ITERATOR (COMANDO CURRENT()): " << endl;
    
    cout << "\nLISTA 1: ";
    for (patronIt_1->First(); !patronIt_1->IsDone(); patronIt_1->Next())
        cout << patronIt_1->Current();
    cout << endl;

    cout << "LISTA 2: ";
    for (patronIt_2->First(); !patronIt_2->IsDone(); patronIt_2->Next())
        cout << patronIt_2->Current();
    cout << endl;

    cout << "LISTA 3: ";
    for (patronIt_3->First(); !patronIt_3->IsDone(); patronIt_3->Next())
        cout << patronIt_3->Current();
    cout << endl;
    
    cout << "\nHACIENDO PUSH_BACK Y SETNEXT A UN NODO PARA LA LISTA 1 NODO NODO 5 [10] y 6 [11]... " << endl;
    nodoLista<int> node_5 {10};
    nodoLista<int> node_6 {11};

    node_5.setNext(node_6);
    lista_1.pushBack(node_5);

    for (patronIt_1->First(); !patronIt_1->IsDone(); patronIt_1->Next())
        cout << patronIt_1->Current();
    cout << endl;

    cout << "\nHACIENDO PUSH_FRONT EN LISTA 1 CON NODO 7 [12]... " << endl;
    nodoLista<int> node_7{12};

    lista_1.pushFront(node_7);

    patronIt_1->Last();
    
    for (patronIt_1->First(); !patronIt_1->IsDone(); patronIt_1->Next())
        cout << patronIt_1->Current();
    cout << endl;

    cout << "\nHACIENDO INSERT EN LISTA 2 EN POS 1 CON NODO 8 [6]... " << endl;
    nodoLista<int> node_8{6};

    lista_2.insert(node_8, 1);

    for (patronIt_2->First(); !patronIt_2->IsDone(); patronIt_2->Next())
        cout << patronIt_2->Current();
    cout << endl;

    cout << "\nHACIENDO POP_BACK EN LISTA 3 [3]..." << endl;

    lista_3.popBack();

    for (patronIt_3->First(); !patronIt_3->IsDone(); patronIt_3->Next())
        cout << patronIt_3->Current();
    cout << endl;

    cout << "\nHACIENDO POP_FRONT EN LISTA 1 [12]..." << endl;

    lista_1.popFront();

    for (patronIt_1->First(); !patronIt_1->IsDone(); patronIt_1->Next())
        cout << patronIt_1->Current();
    cout << endl;

    cout << "\nHACIENDO REMOVE EN LISTA 1 EN POS 2 [3]..." << endl;

    lista_1.remove(2);

    for (patronIt_1->First(); !patronIt_1->IsDone(); patronIt_1->Next())
        cout << patronIt_1->Current();
    cout << endl << endl;

    int a = lista_1.getSize();
    return 0;
}

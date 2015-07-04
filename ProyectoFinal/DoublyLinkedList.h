#pragma once

#include "stdafx.h"

#include "NodoLista.h"

using namespace std;

template<class T>
class DoublyLinkedList{

	template<class T>
	friend ostream & operator<<(ostream &, DoublyLinkedList<T> &);

private:
	NodoLista<T> *inicio, *final;

public:
	DoublyLinkedList(){
		inicio = NULL;
		final = NULL;

	}
	~DoublyLinkedList() {
	}
	void imprimir(ostream& out){
		NodoLista<T>* actual = this->inicio;
		while (actual != NULL){
			out << actual->actual << " ";
			actual = actual->siguiente;
		};
	}
	void insertarFinal(T nodo){
		NodoLista<T>* temp = new NodoLista<T>(nodo);
		if (isEmpty()){
			this->inicio = temp;
			this->final = temp;
		}
		else{
			final->siguiente = temp;
			temp->anterior = final;
			final = temp;
		}
	}

	void insertarInicio(T nodo){
		NodoLista<T>* temp = new NodoLista<T>(nodo);
		if (isEmpty()){
			this->inicio = temp;
			this->final = temp;
		}
		else{
			temp->siguiente = inicio;
			inicio->anterior = temp;
			inicio = temp;
		}
	}
	void insertar(T nodo, int index){
		NodoLista<T>* temp1 = new NodoLista<T>(nodo);
		NodoLista<T>* temp2 = new NodoLista<T>(nodo);
		temp1 = inicio;
		while (--index!=0) {
			temp1 = temp1->siguiente;
		}
		temp2 = temp1->siguiente;
		NodoLista<T>* nuevoNodo = new NodoLista<T>(nodo);
		nuevoNodo->siguiente = temp2;
		temp2->anterior = nuevoNodo;
		temp1->siguiente = nuevoNodo;
		nuevoNodo->anterior = temp1;
	}
	void remover(int index) {
		NodoLista<T>* actual = inicio;
		while (--index != 0) {
			actual = actual->siguiente;
		}
		NodoLista<T>* borrar = actual->siguiente;
		NodoLista<T>*temp = borrar->siguiente;
		delete borrar;
		actual->siguiente = temp;
		temp->anterior = actual;
	}

	bool isEmpty(){
		return this->final == NULL && this->inicio == NULL;
	}
	T getElemento(int index) {
		NodoLista<T>* actual = inicio;
		while (--index != 0) {
			actual = actual->siguiente;
		}
		NodoLista<T>* obtener = actual->siguiente;
		return obtener->actual;
	}


};

template<class T>
ostream & operator<<(ostream & out, DoublyLinkedList<T> & l) {
	l.imprimir(out);
	return out;
}
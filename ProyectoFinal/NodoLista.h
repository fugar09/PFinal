#pragma once

template<class T>
class NodoLista {

	template <class T>
	friend class DoublyLinkedList;

	template <class T>
	friend class Iterador;

private:
	T actual;
	NodoLista<T> *anterior, *siguiente;

public:
	NodoLista(T elemento) {
		this->actual = elemento;
		
		anterior = NULL;
		siguiente = NULL;
	}

	~NodoLista() {
	}

};
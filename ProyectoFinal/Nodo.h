#pragma once
#include "DoublyLinkedList.h"

template <class T>

class Nodo
{
	template <class T>
	friend class Arbol;
private:
	T actual;
	DoublyLinkedList<Nodo<T>*> listaHijos;


public:
	
	Nodo(T elemento)
	{
		this->actual = elemento;
		
	}

	virtual ~Nodo()
	{
	}
};


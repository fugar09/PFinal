#pragma once
#include "Elemento.h"
#include "Operando.h"
#include "DoublyLinkedList.h"
class Operador :
	public Elemento
{
public:
	Operador();
	virtual Operando * operar(DoublyLinkedList<Operando*>)=0;
	virtual char getSymbol() = 0;
	virtual ~Operador();
};


#pragma once
#include "OperadorUnario.h"
class OperadorLogaritmo :
	public OperadorUnario
{
public:
	OperadorLogaritmo();
	Operando * operar(DoublyLinkedList<Operando*> l);
	char getSymbol();
	virtual ~OperadorLogaritmo();
};


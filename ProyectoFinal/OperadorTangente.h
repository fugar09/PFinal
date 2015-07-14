#pragma once
#include "OperadorUnario.h"
class OperadorTangente :
	public OperadorUnario
{
public:
	OperadorTangente();
	Operando * operar(DoublyLinkedList<Operando*>);
	char getSymbol();
	virtual ~OperadorTangente();
};


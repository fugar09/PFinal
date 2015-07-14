#pragma once
#include "OperadorUnario.h"
class OperadorSeno :
	public OperadorUnario
{
public:
	OperadorSeno();
	Operando * operar(DoublyLinkedList<Operando*>);
	char getSymbol();
	virtual ~OperadorSeno();
};


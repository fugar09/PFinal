#pragma once
#include "OperadorUnario.h"
class OperadorCoseno :
	public OperadorUnario
{
public:
	OperadorCoseno();
	Operando * operar(DoublyLinkedList<Operando*>);
	char getSymbol();
	virtual ~OperadorCoseno();
};


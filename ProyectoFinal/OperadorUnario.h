#pragma once
#include "Operador.h"
class OperadorUnario :
	public Operador
{
public:
	OperadorUnario();
	virtual Operando * operar(DoublyLinkedList<Operando*>) = 0;
	virtual char getSymbol() = 0;
	virtual ~OperadorUnario();
};


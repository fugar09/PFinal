#pragma once
#include "Operador.h"
class OperadorBinario :
	public Operador
{
public:
	OperadorBinario();
	virtual Operando * operar(DoublyLinkedList<Operando*>) = 0;
	virtual char getSymbol() = 0;
	virtual ~OperadorBinario();
};


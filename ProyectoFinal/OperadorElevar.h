#pragma once
#include "OperadorBinario.h"
class OperadorElevar :
	public OperadorBinario
{
public:
	OperadorElevar();
	Operando * operar(DoublyLinkedList<Operando*>);
	char getSymbol();
	virtual ~OperadorElevar();
};


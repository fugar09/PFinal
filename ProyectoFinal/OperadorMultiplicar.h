#pragma once
#include "OperadorBinario.h"
class OperadorMultiplicar :
	public OperadorBinario
{
private:
	char s;
public:
	OperadorMultiplicar();
	Operando * operar(DoublyLinkedList<Operando*>);
	char getSymbol();
	void imprimir(ostream &) const;
	virtual ~OperadorMultiplicar();
};


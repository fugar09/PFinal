#pragma once
#include "OperadorBinario.h"
class OperadorDividir :
	public OperadorBinario
{
private:
	char s;
public:
	OperadorDividir();
	Operando * operar(DoublyLinkedList<Operando*>);
	char getSymbol();
	void imprimir(ostream &) const;
	virtual ~OperadorDividir();
};


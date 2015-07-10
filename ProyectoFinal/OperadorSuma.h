#pragma once
#include "OperadorBinario.h"
class OperadorSuma :
	public OperadorBinario
{
private:
	char s;
public:
	OperadorSuma();
	Operando * operar(DoublyLinkedList<Operando*>);
	char getSymbol();
	void imprimir(ostream &) const;
	virtual ~OperadorSuma();
};


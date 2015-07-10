#pragma once
#include "OperadorBinario.h"
class OperadorResta :
	public OperadorBinario
{
private:
	char s;
public:
	OperadorResta();
	Operando * operar(DoublyLinkedList<Operando*>);
	char getSymbol();
	void imprimir(ostream &) const;
	virtual ~OperadorResta();
};


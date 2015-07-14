#include "stdafx.h"
#include "OperadorElevar.h"


OperadorElevar::OperadorElevar()
{
}

Operando *OperadorElevar::operar(DoublyLinkedList<Operando*> l) {
	return new Operando(pow(l.getElemento(0)->get(), l.getElemento(1)->get()));
}

char OperadorElevar::getSymbol()
{
	return 0;
}

OperadorElevar::~OperadorElevar()
{
}

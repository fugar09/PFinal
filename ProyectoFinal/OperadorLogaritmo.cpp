#include "stdafx.h"
#include "OperadorLogaritmo.h"


OperadorLogaritmo::OperadorLogaritmo()
{
}
Operando* OperadorLogaritmo:: operar(DoublyLinkedList<Operando*> l)
{
	return new Operando(log10(l.getElemento(0)->get()));
}
char OperadorLogaritmo::getSymbol()
{
	return 'l';
}


OperadorLogaritmo::~OperadorLogaritmo()
{
}

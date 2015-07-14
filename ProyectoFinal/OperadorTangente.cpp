#include "stdafx.h"
#include "OperadorTangente.h"


OperadorTangente::OperadorTangente()
{
}

Operando * OperadorTangente::operar(DoublyLinkedList<Operando*>l)
{
	return new Operando(tan(l.getElemento(0)->get()));
}

char OperadorTangente::getSymbol()
{
	return 't';
}


OperadorTangente::~OperadorTangente()
{
}

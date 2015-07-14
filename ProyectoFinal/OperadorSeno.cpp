#include "stdafx.h"
#include "OperadorSeno.h"


OperadorSeno::OperadorSeno()
{
}

Operando * OperadorSeno::operar(DoublyLinkedList<Operando*>l)
{
	return new Operando(sin(l.getElemento(0)->get()));
}

char OperadorSeno::getSymbol()
{
	return 's';
}


OperadorSeno::~OperadorSeno()
{
}

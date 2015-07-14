#include "stdafx.h"
#include "OperadorCoseno.h"


OperadorCoseno::OperadorCoseno()
{
}

Operando * OperadorCoseno::operar(DoublyLinkedList<Operando*>l)
{
	return new Operando(cos(l.getElemento(0)->get()));;
}


OperadorCoseno::~OperadorCoseno()
{
}

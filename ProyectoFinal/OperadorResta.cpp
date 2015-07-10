#include "stdafx.h"
#include "OperadorResta.h"


OperadorResta::OperadorResta()
{
	s = '-';
}


OperadorResta::~OperadorResta()
{
}
Operando * OperadorResta::operar(DoublyLinkedList<Operando*> l) {
	return new Operando(l.getElemento(0)->get() - l.getElemento(1)->get());
}
void OperadorResta::imprimir(ostream& out) const {
	out << this->s;
}
char OperadorResta::getSymbol() {
	return s;
}

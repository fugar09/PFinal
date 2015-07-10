#include "stdafx.h"
#include "OperadorMultiplicar.h"


OperadorMultiplicar::OperadorMultiplicar()
{
	s = '*';
}


OperadorMultiplicar::~OperadorMultiplicar()
{
}
Operando * OperadorMultiplicar::operar(DoublyLinkedList<Operando*> l) {
	return new Operando(l.getElemento(0)->get() * l.getElemento(1)->get());
}
void OperadorMultiplicar::imprimir(ostream& out) const {
	out << this->s;
}
char OperadorMultiplicar::getSymbol() {
	return s;
}

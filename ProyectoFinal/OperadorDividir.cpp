#include "stdafx.h"
#include "OperadorDividir.h"


OperadorDividir::OperadorDividir()
{
	s = '/';
}


OperadorDividir::~OperadorDividir()
{
}
Operando * OperadorDividir::operar(DoublyLinkedList<Operando*> l) {
	return new Operando(l.getElemento(0)->get() / l.getElemento(1)->get());
}
void OperadorDividir::imprimir(ostream& out) const {
	out << this->s;
}
char OperadorDividir::getSymbol() {
	return s;
}
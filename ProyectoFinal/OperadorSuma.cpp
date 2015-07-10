#include "stdafx.h"
#include "OperadorSuma.h"


OperadorSuma::OperadorSuma()
{
	s = '+';
}


OperadorSuma::~OperadorSuma()
{
}

Operando * OperadorSuma::operar(DoublyLinkedList<Operando*> l) {
	return new Operando(l.getElemento(0)->get() + l.getElemento(1)->get());
}
void OperadorSuma::imprimir(ostream& out) const {
	out << this->s;
}
char OperadorSuma::getSymbol() {
	return s;
}
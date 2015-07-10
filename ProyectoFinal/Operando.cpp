#include "stdafx.h"
#include "Operando.h"


Operando::Operando(double i)
{
	this->i = i;
}
Operando::~Operando()
{
}
double Operando::get() {
	return i;
}
void Operando::imprimir(ostream& out) const {
	out << i;
}
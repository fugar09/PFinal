#include "stdafx.h"
#include "Operacion.h"


Operacion::Operacion(string expresion)
{
	this->expresion = expresion;
}


Operacion::~Operacion()
{
}

void Operacion::imprimir(ostream& out) const {
	out << expresion;
}
string Operacion::getExpresion() {
	return this->expresion;
}
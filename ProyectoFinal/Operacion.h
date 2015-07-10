#pragma once
#include "Elemento.h"
using namespace std;

class Operacion :
	public Elemento
{
private:
	string expresion;
public:
	Operacion(string);
	virtual ~Operacion();
	void imprimir(ostream &) const;
	string getExpresion();
};


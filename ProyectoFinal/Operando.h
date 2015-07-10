#pragma once
#include "Elemento.h"

using namespace std;

class Operando:public Elemento
{
private:
	double i;
public:
	Operando(double);
	double get();
	void imprimir(ostream &) const;
	virtual ~Operando();
};


#pragma once
#include "stdafx.h"
#include "Nodo.h"
#include "DoublyLinkedList.h"
#include "Operando.h"
#include "Operador.h"
#include "Operacion.h"
#include "OperadorSeno.h"
#include "OperadorCoseno.h"
#include "OperadorTangente.h"
#include "OperadorLogaritmo.h"
#include "OperadorFuncion.h"
#include "OperadorElevar.h"

#define OPERANDO 0
#define OPERADOR_ELEV 1
#define OPERADOR_SUMA 2
#define OPERADOR_RESTA 3
#define OPERADOR_MULTI 4
#define OPERADOR_DIV 5
#define OPERADOR_SENO 6
#define OPERADOR_COSENO 7
#define OPERADOR_TAN 8
#define OPERADOR_LOG10 9
#define OPERADOR_FUNC 10


template<class T>
class Arbol
{
	template<class T>
	friend ostream & operator<<(ostream &, Arbol<T> &);

private:
	Nodo<T> *raiz;
	static const int NUM_OPERADORES = 10;
	const char OPERADORES[NUM_OPERADORES] = { '^','+', '-', '/', '*','s','t','c','l','f' };
	static const char LEFT_PARENTHESIS = '(';
	static const char RIGHT_PARENTHESIS = ')';
public:
	Arbol() {
		raiz = NULL;
	}

	Arbol(Operacion* op)
	{
		Nodo<T> *e;

		e = armarRec(op->getExpresion()); //armar el arbol utilizando la recursión

		raiz = e;
	}
	void eliminarParentesisInnecesarios(string & string) {
		bool continuar = true;
		while (continuar) {
			continuar = false;
			if (string[0] == LEFT_PARENTHESIS && string[string.length() - 1] == RIGHT_PARENTHESIS) {
				int parentesis = 1;
				bool quitarParentesis = true;
				for (unsigned int i = 1; i < string.length() - 1 && quitarParentesis; ++i) {
					char c = string[i];
					if (c == LEFT_PARENTHESIS) {
						parentesis++;
					}
					else if (c == RIGHT_PARENTHESIS) {
						parentesis--;
					}
					if (parentesis < 1) {
						quitarParentesis = false;
					}
				}
				if (quitarParentesis) {
					string = string.substr(1, string.length() - 2);
					continuar = true;
				}
			}
		}
	}
	int buscarPrecedencia(string string) {
		//Función que retorna la posición donde esta el signo de menor precedencia en una expresión matemática

		int index = -1;
		int parentesis = 0;
		for (int k = 0; k < NUM_OPERADORES && index == -1; k++) {
			for (unsigned int i = 0; i < string.length() && index == -1; ++i) {
				char c = string[i];
				if (c == LEFT_PARENTHESIS) {
					parentesis++;
				}
				else if (c == RIGHT_PARENTHESIS) {
					parentesis--;
				}
				else if (parentesis == 0 && c == OPERADORES[k]) {
					index = i;
				}
			}
		}
		return index;
	}
	bool isOnlyDouble(string exp)
	{
		//Función que retorna si el la expresión que se revisa es solo un double, retorna si sin son solo números, sino false
		const char* str = exp.c_str();
		char* endptr = 0;
		strtod(str, &endptr);

		if (*endptr != '\0' || endptr == str)
			return false;
		return true;
	}
	double convertToDouble(string op) {
		//Función que devuelve el valor en double de un string
		double d;
		d = atof(op.c_str());
		return d;
	}
	int tipoExpresion(string exp) {
		//Función que retorna que tipo de expresión se tiene
		int size = exp.length();
		int tipo = -1;
		if (isOnlyDouble(exp)) {
			tipo = OPERANDO;
		}
		else if (exp == "+") {
			tipo = OPERADOR_SUMA;
		}
		else if (exp == "-") {
			tipo = OPERADOR_RESTA;
		}
		else if (exp == "*") {
			tipo = OPERADOR_MULTI;
		}
		else if (exp == "/") {
			tipo = OPERADOR_DIV;
		}
		else if (exp == "s") {
			tipo = OPERADOR_SENO;
		}
		else if (exp == "t") {
			tipo = OPERADOR_TAN;
		}
		else if (exp == "l") {
			tipo = OPERADOR_LOG10;
		}
		else if (exp == "c") {
			tipo = OPERADOR_COSENO;
		}if (exp == "f") {
			tipo = OPERADOR_FUNC;
		}else {
			tipo = OPERADOR_ELEV;
		}
		return tipo;
	}


	void imprimir(Nodo<T>* nodo, ostream& out, int profundidad) {
		if (nodo->listaHijos.getElemento(0) != NULL) {
			imprimir(nodo->listaHijos.getElemento(0), out, profundidad + 1);
		}
		for (int i = 0; i < profundidad; ++i) {
			cout << "\t";
		}
		out << nodo << endl;
		if (nodo->listaHijos.getElemento(1) != NULL) {
			imprimir(nodo->listaHijos.getElemento(1), out, profundidad + 1);
		}
	}

	int tipoOperador(char operador) {
		int posicion;
		for (unsigned int i = 0; i < NUM_OPERADORES; i++){
			if (operador == OPERADORES[i]) {
				posicion = i;
			}
		}
		if (posicion >= 0 && posicion <= 4) {
			return 2; //El operador es binario
		}else if (posicion >= 5 && posicion <= 8) {
			return 1; //El operador es unario
		}else if (posicion == 9) {
			return 3; //El operador es ternario
		}
	}
	Nodo<T>* armarRec(string exp) {
		Nodo<T>* e=NULL;
		
	
		eliminarParentesisInnecesarios(exp);
		double op = 0.0;
		if (isOnlyDouble(exp)) {
			op = convertToDouble(exp);
			e =new Nodo<T>( new Operando(op));
			return e;
		}
		else {
			int prec = buscarPrecedencia(exp);
			int tipoOp = tipoOperador(exp[prec]);
			switch (tipoOp)
			{
			case 1:
				//Para caso de Operadores Unarios
				int size = exp.length();  //se calcula el largo de la expresión
										  //se divide al expresión en tres partes
				string exp1 = exp.substr(0, prec); //una parte para el hijo Izquierdo
				string exp2 = exp.substr(prec, 1);// el centro seria el operador 
				switch (tipoExpresion(exp2)) {
					//se revisa que tipo de operador es
				case OPERADOR_SENO:
					e = new Nodo<T>(new OperadorSeno());
					break;
				case OPERADOR_COSENO:
					e = new Nodo<T>(new OperadorCoseno());
					break;
				case OPERADOR_TAN:
					e = new Nodo<T>(new OperadorTangente());
					break;
				case OPERADOR_LOG10:
					e = new Nodo<T>(new OperadorLogaritmo());
					break;
				}
				//se vuelve a llamar recursivamente el metodo con los hijos como parametros, hasta que devuelva un operando
				Nodo<T>* p1 = armarRec(exp1);
				e->listaHijos.insertarInicio(p1);

			case 2:
				//Para caso de Operadores Binarios
				int size = exp.length();  //se calcula el largo de la expresión
										  //se divide al expresión en tres partes
				string exp1 = exp.substr(0, prec); //una parte para el hijo Izquierdo
				string exp2 = exp.substr(prec, 1);// el centro seria el operador (+/-*)
				string exp3 = exp.substr(prec + 1, size);// la ultima parte para el hijo derecho

				switch (tipoExpresion(exp2)) {
					//se revisa que tipo de operador es
				case OPERADOR_SUMA:
					e = new Nodo<T>(new OperadorSuma());
					break;
				case OPERADOR_RESTA:
					e = new Nodo<T>(new OperadorResta());
					break;
				case OPERADOR_MULTI:
					e =new Nodo<T>(new OperadorMultiplicar());
					break;
				case OPERADOR_DIV:
					e =new Nodo<T>(new OperadorDividir());
					break;
				case OPERADOR_ELEV:
					e = new Nodo<T>(new OperadorElevar());
					break;
				}
				//se vuelve a llamar recursivamente el metodo con los hijos como parametros, hasta que devuelva un operando
				Nodo<T>* p1 = armarRec(exp1);
				e->listaHijos.insertarInicio(p1);
				Nodo<T>* p2 = armarRec(exp3);
				e->listaHijos.insertarFinal(p2);
			case 3:
				//Para caso de operadores ternarios
			}
			
		}
		return e;
	}
	bool isOperator(Nodo<T>* e) {
		//Metodo que devuelve si el elemento revisado es un operador o no
		return !(e->listaHijos->isEmpty()); //en caso de que el elemento revisado tenga hijos en nulo, se sabe que es un operando, por lo cual retorna false

	}
	Operando* getValue(Nodo<T>* e) {
		/*Metodo que recorre el arbol devolviendo los diferente Operando según el nivel, utilizando la recursividad*/
		if (!isOperator(e)) {// Si el elemento que se revisa no es un operador
			Operando* opnd = static_cast<Operando*>(e->actual); //se trata como si fuera un operando
			return opnd; //retorna el valor del operando
		}
		else {
			Operador*op = dynamic_cast<Operador*>(e->actual);
			int tipoOp = tipoOperador(op->getSymbol());
			switch (tipoOp) {
			case 2:
				Operando * a = getValue(e->listaHijos.getElemento(0)); // se llama recursivamente a esta misma función, hasta q devuelva al operando correspondiente
				Operando * b = getValue(e->listaHijos.getElemento(1));
				if (e->listaHijos.getElemento(0) == NULL || e->listaHijos.getElemento(1) == NULL) {
					return op->operar(dynamic_cast<DoublyLinkedList<Operando*>>(e->listaHijos)); //se realiza la operación utilizando las propiedades del polimorfismo de ese metodo
				}
				else {

				}
			}
		}
	}
	double resolver() {
		//Metodo que devuelve el resultado de un arbol
		double total = 0.0;
		total = getValue(raiz)->get();
		return total;
	}

	virtual ~Arbol()
	{
	}
};

template<class T>
ostream & operator<<(ostream & out, Arbol<T> & a) {
	a.imprimir(a.raiz, out, 0);
	return out;
}

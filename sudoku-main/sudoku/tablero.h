#pragma once
#ifndef TABLERO_H
#define TABLERO_H
#include "celda.h"

const int MAX = 99;
class Tablero {
private:
	Celda tablero[MAX][MAX];
	int dim;
public:
	Tablero();
	Tablero(int dim);
	//consulta joder ya me entran ganas de pegarme un tiro
	int dame_dim() const;
	Celda dame_celda(int fila, int col) const;
	//modificadores, estoy hasta los cojones de las 400 advertencias que me salen por no estar las fucniones en el cpp joder
	void set_celda(int fila, int col, const Celda& c);
};

#endif
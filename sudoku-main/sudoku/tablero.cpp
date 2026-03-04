#include "tablero.h"
#include "celda.h"
#include <iostream>
using namespace std;
Tablero::Tablero() {
	dim = 9;
}
Tablero::Tablero(int dim) {
	this->dim = dim;
}
//consulta joder ya me entran ganas de pegarme un tiro
int Tablero::dame_dim() const {
	return dim;
}
Celda Tablero::dame_celda(int fila, int col) const {
	return tablero[fila][col];
}
//modificadores, estoy hasta los cojones de las 400 advertencias que me salen por no estar las fucniones en el cpp joder
void Tablero::set_celda(int fila, int col, const Celda& c) {
	tablero[fila][col] = c;
}
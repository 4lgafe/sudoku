#include "reglas.h"
#include "tablero.h"
#include <iostream>
using namespace std;
Reglas::Reglas() {
	contador = 0;
}
Reglas::Reglas(const Tablero& tableroInicial) {
	tablero = tableroInicial;
	contador = 0;
}
//consultoras, el numero de advertencias sigen aumentando, como mis ganas de tomarme unas cervezas
int Reglas::dame_dimension()const {
	return tablero.dame_dim();
}
int Reglas::dame_celda(int f, int c)const {
	return tablero.dame_celda(f, c).dame_valor();//pedimos la celda y luego usamos dame valor para coger el valor,seguido porque esta dame valor en celda
}
bool Reglas::terminado()const{
	//comprobaremos si ha algun valor vacio si no lo hay pues no esta terminado
	int dim;
	dim = tablero.dame_dim();
	bool terminado = true;
	for(int i=0; i<dim; i++){
		for (int j = 0; j < dim; j++) {
			if (tablero.dame_celda(i, j).es_vacia())terminado = false;
		}
	}
	return terminado;
}
bool Reglas::bloqueo()const {}
int Reglas::dame_num_celdas_bloqueadas()const {}
void Reglas::dame_celda_bloqueada(int p, int& f, int& c)const {}
bool Reglas::es_valor_posible(int f, int c, int v)const {}
//modificadiores ¿¿DIO?? 
bool Reglas::pon_valor(int f, int c, int v) {}
bool Reglas::quita_valor(int f, int c) {}
void Reglas::reset() {}
void Reglas::autocompletar() {}
//iniciador, no, no es DIO, es ESQUIZOFRENIA Turu tururú tururú turutúTurururururururúuuuu TÚRURÚ  TÚ TÚ  TURURÚ
void Reglas::carga_sudoku(std::ifstream& in) {}
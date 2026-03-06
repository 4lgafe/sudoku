#include "reglas.h"
#include "tablero.h"
#include <iostream>
#include <vector>
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

bool Reglas::bloqueo(int f, int c)const {
	//comprobamos cada valor posible que puede tener la celda
	int dim = tablero.dame_dim();
	bool bloqueada=true;
	for (int i = 0; i < dim; i++) {
		if (es_valor_posible(f, c, i)) bloqueada = false;
	}
	return bloqueada;
}
int Reglas::dame_num_celdas_bloqueadas() {
	//tendremos que comprobar celda a celda si es celda bloqueada
	int dim = tablero.dame_dim();
	int nBloq = 0;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (bloqueo(i, j)) {
				//creamos de paso el array de coordenadas de celdas bloqueadas ya que recorremos todo el tablero
				bloqueadas[nBloq].fil = i;
				bloqueadas[nBloq].col = j;
				nBloq++;
			}
		}
	}
	return nBloq;
}

coords Reglas::dame_celda_bloqueada(int p) {
	//comprobamos si la posicion existe, si no devolveremos -1 como convenio, joder me tomaba unas cuantas cervezas agustisimo ahora mismo, pero vamos de esto que pides dos al camarero para tener la segunda a mano mas rapido que un pitstop de f1
	coords coordenadas;
	coordenadas.fil = -1;
	coordenadas.col = -1;
	if (p > dame_num_celdas_bloqueadas()) coordenadas = bloqueadas[p];
	return coordenadas;
}

bool Reglas::es_valor_posible(int f, int c, int v)const {
	int dim = tablero.dame_dim();
	bool valida = true;
	//si no es vacia no es valida
	if (tablero.dame_celda(f, c).es_vacia()) {
		//comprobacion de la fila:
		for (int i = 0; i < dim; i++) {
			if(tablero.dame_celda(f, i).dame_valor()==v) valida = false;
		}
		//comprobacion columna
		if (valida) {
			for (int i = 0; i < dim; i++) {
				if (tablero.dame_celda(i, c).dame_valor() == v) valida = false;
			}
		}
		//comprobacion bloque, si dividimos entre tres truncando conseguimos el numero de bloque, si multiplicamos por 3 la posicion, funciona sin problema porque inicia desde 0. ejs 2/3=0, 0*3= 0 inicio bloque pos 0, 5/3=1, 1*3=3 inicio pos=3, 3/3=1 1*3=3...
		if (valida) {
			for (int i = ((f / 3) * 3); i < ((f / 3) * 3) + 3; i++) {
				for (int j = ((c / 3) * 3); j < ((c / 3) * 3) + 3; j++) {
					if (tablero.dame_celda(i, j).dame_valor() == v) valida = false;
				}
			} 
		}
	}
	else valida = false;
	return valida;
}
//modificadiores ¿¿DIO?? 
bool Reglas::pon_valor(int f, int c, int v) {}
bool Reglas::quita_valor(int f, int c) {}
void Reglas::reset() {}
void Reglas::autocompletar() {}
//iniciador, no, no es DIO, es ESQUIZOFRENIA Turu tururú tururú turutúTurururururururúuuuu TÚRURÚ  TÚ TÚ  TURURÚ
void Reglas::carga_sudoku(std::ifstream& in) {}
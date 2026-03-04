#pragma once
#ifndef REGLAS_H
#define REGLAS_H
#include "tablero.h"
#include <fstream>

typedef struct coords {
	int fil;
	int col;
};
const int MAX_BLOQ = 10000;
typedef coords posBloqueadas[MAX_BLOQ];

class Reglas {
private:
	Tablero tablero;
	int contador;
	posBloqueadas bloqueadas;
public:
	Reglas();
	Reglas(const Tablero& tableroInicial);
	//consultoras, el numero de advertencias sigen aumentando, como mis ganas de tomarme unas cervezas
	int dame_dimension()const;
	int dame_celda(int f, int c)const;
	bool terminado()const;
	bool bloqueo()const;
	int dame_num_celdas_bloqueadas()const;
	void dame_celda_bloqueada(int p, int& f, int& c)const;
	bool es_valor_posible(int f, int c, int v)const;
	//modificadiores ¿¿DIO?? 
	bool pon_valor(int f, int c, int v);
	bool quita_valor(int f, int c);
	void reset();
	void autocompletar();
	//iniciador, no, no es DIO, es ESQUIZOFRENIA Turu tururú tururú turutúTurururururururúuuuu TÚRURÚ  TÚ TÚ  TURURÚ
	void carga_sudoku(std:: ifstream& in);
};

#endif
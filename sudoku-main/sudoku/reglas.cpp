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
bool Reglas::bloqueo(int f, int c)const {//no funciona en ciertos casos impleentar en vase a esto es valida, y hacer un for tipo que pruebe todos los numeros
	//el bloqueo se da cuando las cosas cosean y se bloquean por lo que da un bloqueo que bloquea el bloque. Nahh esto se da cuando el conjunto de numeros ocupados en la fila, columna y bloque de la celda contienen los numeros del 1-9 por lo que no se puede colocar ningun numero y  cosas cosean y se bloquean por lo que da un bloqueo que bloquea el bloque.
	vector<bool> usadas(tablero.dame_dim() + 1, false);
	int dim = tablero.dame_dim();
	//no se si se puede usar el vector pero no me dejaba hacerlo asi con posiciones variables con el array otra opcion seria bool usadas [10]={false}
	bool bloqueada = true;
	//si esta usada contara como que no esta bloqueada
	if (tablero.dame_celda(f, c).es_vacia()) {
		//comprobacion de la fila:
		for (int i = 0; i < dim; i++) {
			usadas[tablero.dame_celda(f, i).dame_valor()] = true;
		}
		//comprobacion columna
		for (int i = 0; i < dim; i++) {
			usadas[tablero.dame_celda(i, c).dame_valor()] = true;
		}
		//comprobacion bloque, si dividimos entre tres truncando conseguimos el numero de bloque, si multiplicamos por 3 la posicion, funciona sin problema porque inicia desde 0. ejs 2/3=0, 0*3= 0 inicio bloque pos 0, 5/3=1, 1*3=3 inicio pos=3, 3/3=1 1*3=3...
		for (int i = ((f / 3) * 3); i < ((f / 3) * 3) + 3; i++) {
			for (int j = ((c / 3) * 3); j < ((c / 3) * 3) + 3; j++) {
				usadas[tablero.dame_celda(i, j).dame_valor()] = true;
			}
		}
		for (int i = 1; i < dim + 1; i++) if (!usadas[i])bloqueada = false;
	}
	else bloqueada = false;
	return bloqueada;
}
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
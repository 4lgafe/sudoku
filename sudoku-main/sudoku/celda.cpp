#include "celda.h"
#include <iostream>
using namespace std;

Celda::Celda() {
	v = 0;
	estado = VACIA;
}
Celda::Celda(int v, tEstado estado) {
		this->v = v;// el this hace referencia a que una de las variables es de la clase y la otra es de su puta madre
		this->estado = estado;
}
/* métodos de consultaaaaaaahh~~~~~~*/
bool Celda::es_vacia() const {
	return estado == VACIA;
}
bool Celda::es_original() const {
	return estado == VACIA;
}
bool Celda::es_ocupada() const {
	return estado == VACIA;
}
int Celda::dame_valor() const {
	return v;
}
/* métodos modificadores*/
void Celda::set_valor(int valor) {
	v = valor;
}
void Celda::set_ocupada() {
	estado == OCUPADA;
}
void Celda::set_original() {
	estado == ORIGINAL;
}
void Celda::set_vacia() {
	estado == VACIA;
}
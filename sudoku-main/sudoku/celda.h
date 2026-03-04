#pragma once
#ifndef CELDA_H
#define CELDA_H

enum tEstado {ORIGINAL, OCUPADA, VACIA};

class Celda {
private:
	int v;
	tEstado estado;
public:
	Celda();
	Celda(int v, tEstado estado);
	/* métodos de consulta */
	bool es_vacia() const;
	bool es_original() const;
	bool es_ocupada() const;
	int dame_valor() const;
	/* métodos modificadores*/
	void set_valor(int valor);
	void set_ocupada();
	void set_original();
	void set_vacia();
};

#endif
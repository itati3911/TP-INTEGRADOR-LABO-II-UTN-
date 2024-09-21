#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

#include "Persona.h"
#include "Fecha.h"
#include "Helpers.h"

class Cliente : public Persona
{
public:
	void setCategoria(bool categoria);
	bool getCategoria() const;

	void cargarCliente();
	void mostrarCliente();
	void mostrarClienteSinID();

	void mostrarEncabezado();
	void mostrarEncabezadoSinID();

private:
	bool _categoria; // 1- MAYORISTA y 0-MINORISTA
};

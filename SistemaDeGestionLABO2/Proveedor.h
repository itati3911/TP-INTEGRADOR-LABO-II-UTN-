#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

#include "Persona.h"
#include "Fecha.h"
#include "Helpers.h"

class Proveedor : public Persona
{
public:
	void setTipo(const char* tipo);
	const char* getTipo() const;

	void cargarProveedor();
	void mostrarProveedor();
	void mostrarProveedorSinID();

	void mostrarEncabezado();
	void mostrarEncabezadoSinID();

private:
	char _tipo[50]; // GOLOSINAS,CONGELADOS, LACTEOS, VERDULERIA, ETC
};

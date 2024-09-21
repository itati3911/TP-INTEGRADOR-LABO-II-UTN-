#pragma once
#include <iostream>
using namespace std;
#include "Fecha.h"
#include <iomanip>
#include "Helpers.h"

class Persona
{
public:

	Persona();

	void Cargar();
	void Mostrar();
	void Mostrar2();

	void setId(int id);
	void setDni(int d);
	void setNombre(const char* nombre);
	void setApellido(const char* apellido);
	void setDomicilio(const char* domicilio);
	void setEmail(const char* email);
	void setFechaAlta();
	void setEstado(bool estado);

	int getDNI();
	int getId();
	char* getNombre();
	char* getApellido();
	char* getDomicilio();
	char* getEmail();
	Fecha getFechaAlta();
	bool getEstado();

protected:
	int _dni, _id;
	char _nombre[40], _apellido[40];
	char _direccion[100], _email[50];
	Fecha _fechaAlta;
	bool _estado;
};


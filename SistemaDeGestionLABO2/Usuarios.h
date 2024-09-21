#pragma once
#include <iostream>
#include <iomanip>
#include "Helpers.h"

using namespace std;

#include "ArchivosManager.h"

class Usuarios
{
public:

	// CONSTRUCTORES
	Usuarios();
	Usuarios(const char* usuario, const char* passw); 

	// SETTERS
	void SetUsuario();
	void SetPassw();
	void SetId(int id);
	void setEstado(bool estado);

	// GETTERS
	const char* GetNombre() const;
	const char* GetPassw() const;
	int GetId() const;
	bool getEstado() const;

	// METODOS DE CLASE
	void Mostar() const;
	void Cargar();
	bool verificarCredenciales(const char* usuario, const char* passw) const;
	void cambiarUsuario(const char* usuario, const char* passw);

	// SOBRECARGA DE OPERADORES PARA USAR OBJETOS USUARIOS
	bool operator==(const Usuarios& otro) const;

private:
	int _id;
	char _usuario[16];
	char _passw[16];
	bool _estado;
};


#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Proveedor;

class ArchivosProveedores
{
public:
	ArchivosProveedores(const char* n);

	int ObtenerUltimoIdProveedor() const;
	bool AltaProveedor(Proveedor reg);
	bool BajaProveedor(int id);
	bool ModificarProveedor(Proveedor reg, int pos);
	bool ListarProveedor(Proveedor reg) const;
	bool sobreEscribirRegistro(Proveedor reg, int pos);
	int BuscarProveedorXID(int id, FILE* p) const;
	int BuscarProveedorXDNI(int dni, FILE* P) const;
	int BuscarPosicion(Proveedor reg);
	Proveedor BuscarProveedor(int n) const;

private:
	char _nombreArchivo[30];

};


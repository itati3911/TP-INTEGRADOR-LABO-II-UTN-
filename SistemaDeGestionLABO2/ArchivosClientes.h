#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Cliente;

class ArchivosClientes
{
public:
	ArchivosClientes(const char* n);

	int ObtenerUltimoIdCliente() const;
	bool AltaCliente(Cliente reg);
	bool BajaCliente(int id);
	bool ModificarCliente(Cliente reg, int pos);
	bool ListarCliente(Cliente reg) const;
	bool sobreEscribirRegistro(Cliente reg, int pos);
	int BuscarClienteXID(int id, FILE* p) const;
	int BuscarCLienteXDNI(int dni, FILE* P) const;
	int BuscarPosicion(Cliente reg);
	Cliente BuscarCliente(int n) const;

private:
	char _nombreArchivo[30];
};

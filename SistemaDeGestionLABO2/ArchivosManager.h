#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Usuarios;
class Producto;
class DetalleFactura;

class ArchivosManager
{
public:
	ArchivosManager(const char* n);

	// METODOS PARA Usuario
	int ObtenerUltimoId() const;
	Usuarios BuscarUsuario(const char* usuario, const char* passw) const;
	bool AltaUsuario(Usuarios reg);
	bool BajaUsuario(int id);
	bool ModificarUsuario(int id, const char* nuevoUsuario, const char* nuevaPassw);
	bool ListarUsuarios(Usuarios reg);

	// METODOS PARA Producto
	int ObtenerUltimoIdProducto() const;
	bool AltaProducto(Producto reg);
	bool BajaProducto(int id);
	bool ModificarProducto(Producto reg, int pos);
	bool ListarProducto(Producto reg) const;
	bool ListarStock(Producto reg) const;
	bool sobreEscribirRegistroProducto(Producto reg, int pos);
	int BuscarProductoXID(int id, FILE* p) const;
	int BuscarStockXID(int id, FILE* p) const;
	int BuscarProductoXNombre(const char* nombre) const;
	int BuscarPosicion(Producto reg);
	Producto BuscarProducto(int n) const;

	bool verificarStock(Producto reg, int cantidad);
	bool ajustarStock(Producto reg, int cantidad);
	bool aumentarStock(int id, int cantidad);

	// METODOS PARA DETALLE
	bool altaDetalle(DetalleFactura reg);
	bool bajaDetalle(int id);
	bool ListarDetalle(DetalleFactura reg);

private:
	char _nombreArchivo[30];
};

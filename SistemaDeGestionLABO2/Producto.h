#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

#include "Fecha.h"
#include "Helpers.h"

class Producto
{
public:
	Producto();
	Producto(int id, const char* nombre, int precioVenta, int precioCompra, int cantidad);

	void CargarProducto();
	void MostrarEncabezado();
	void MostrarEncabezadoSinID();
	void MostrarEncabezadoYSuStock();
	void MostrarInformacionProducto();
	void MostrarInformacionProductoSinID();
	void MostrarProductoYSuStock();

	void SetId(int id);
	void SetCantidad(int cantidad);
	void SetNombre(const char* nombre);
	void SetFecha();
	void SetEstado(bool estado);
	void SetPrecioVenta(float precioVenta);
	void SetPrecioCompra(float precioCompra);
	void SetDescripcion(const char* desc);

	int GetId() const;
	int GetCantidad() const;
	char* GetNombre();
	char* GetDescripcion();
	Fecha GetFecha() const;
	bool GetEstado() const;
	float GetPrecioVenta() const;
	float GetPrecioCompra() const;

protected:
	int _id, _cantidad;
	float _precioVenta, _precioCompra;
	char _nombre[40], _descripcion[100];
	Fecha _fecha;
	bool _estado;
};

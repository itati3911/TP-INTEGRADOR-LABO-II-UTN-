#pragma once

// Esta clase gestionara todos los objetos del programa
// para interactuar con ArchivosManager.h y el Menu.h

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#include "Helpers.h"
#include "ArchivosManager.h"
#include "ArchivosClientes.h"
#include "ArchivosProveedores.h"
#include "ArchivoFactura.h"
#include "Usuarios.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "Producto.h"
#include "Factura.h"
#include "DetalleFactura.h"


class Manager
{
public:
	// METODOS PARA GESTIONAR USUARIOS
	void MostrarEncabezadoUsuario();

	bool entradaAlSistema();
	void AltaUsuarios();
	void BajaUsuario();
	void MoidificarUsuarios();
	void listarUsuarios();
	bool permisosAdmin();

	// METODOS PARA GESTIONAR PRODUCTOS
	void MostrarEncabezadoProductos();
	void MostrarEncabezadoProductosSinID();
	void mostrarEncabezado2();
	void mostrarEncabezado2SinID();
	void AltaProducto();
	void BajaProducto();
	void MoidificarProducto();
	void listarProducto();
	void BuscarProductoXID();
	void BuscarProductoXNombre();

	// METODOS PARA GESTIONAR UNA COMPRA Y STOCK
	void CargarCompra();
	void ListarStock();
	void BuscarStock();

	// METODOS PARA GESTIONAR CLIENTES
	void AltaCliente();
	void BajaCliente();
	void ModificarCliente();
	void ListarClientes();
	void BuscarCliente();

	// METODOS PARA GESTIONAR PROVEEDORES
	void AltaProveedor();
	void BajaProveedor();
	void ModificarProveedor();
	void ListarProveedor();
	void BuscarProveedor();

	// METODOS PARA GESTIONAR VENTAS
	void CargarVenta();

	// METODOS PARA REPORTES
	void listarVentas();
	void reporteCaja();


	// SETTERS
	void setUsuarios(Usuarios usuario);

private:
	// INSTANCIAS PARA GESTIONAR USUARIOS
	ArchivosManager _reg = ArchivosManager("Usuarios.dat");
	Usuarios _usuarios;

	// INSTANCIAS PARA GESTIONAR PRODUCTOS
	ArchivosManager _regProductos = ArchivosManager("Productos.dat");
	Producto _producto;

	// INSTANCIAS PARA GESTIONAR CLIENTES
	ArchivosClientes _regClientes = ArchivosClientes("Clientes.dat");
	Cliente _cliente;

	// INSTANCIAS PARA GESTIONAR PROVEEDORES
	ArchivosProveedores _regProveedores = ArchivosProveedores ("Proveedores.dat");
	Proveedor _proveedor;

	// INTANCIAS PARA GESTIONAR FACTURAS

	ArchivoFactura _regFacturas = ArchivoFactura("Facturas.dat");
	Factura _factura;
	ArchivosManager _regDetalle = ArchivosManager("DetalleFactura.dat");
	DetalleFactura _detalle;

};

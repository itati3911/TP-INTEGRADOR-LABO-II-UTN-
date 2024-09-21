#include "Producto.h"

Producto::Producto()
{
	_id = -1;
	_precioVenta = 0.0;
	_precioCompra = 0.0;
	_cantidad = 0;
	strcpy_s(_nombre, "");
	strcpy_s(_descripcion, "");
	_fecha = Fecha(0, 0, 0);
	_cantidad = 0;
	_estado = true;
}
Producto::Producto(int id, const char* nombre, int precioVenta, int precioCompra, int cantidad)
{

	SetId(id);
	SetNombre(nombre);
	SetPrecioVenta(precioVenta);
	SetPrecioCompra(precioCompra);
	SetCantidad(cantidad);
	_fecha.FechaActual();
	_estado = true;
}

void Producto::CargarProducto()
{
	float precioVenta, precioCompra;
	char nombre[40], desc[100];
	int cantidad;

	cin.ignore();
	cout << endl
		<< "NOMBRE: ";
	cin.getline(nombre, sizeof(nombre));
	cout << endl
		<< "DESCRIPCION: ";
	cin.getline(desc, sizeof(desc));
	cout << endl
		<< "CANTIDADES: ";
	cin >> cantidad;
	cout << endl
		<< "PRECIO DE VENTA: ";
	cin >> precioVenta;
	cout << endl
		<< "PRECIO DE COMPRA: ";
	cin >> precioCompra;

	SetFecha();
	SetNombre(nombre);
	SetDescripcion(desc);
	SetPrecioVenta(precioVenta);
	SetPrecioCompra(precioCompra);
	SetCantidad(cantidad);
	SetEstado(true);
}
void Producto::MostrarEncabezado()
{
	cout << setw(5) << "ID";
	cout << setw(15) << "NOMBRE";
	cout << setw(45) << "DESCRIPCION";
	cout << setw(20) << "PRECIO VENTA";
	cout << setw(35) << "PRECIO COMPRA";
	cout << setw(55) << "FECHA DE ALTA" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void Producto::MostrarEncabezadoSinID()
{
	cout << setw(15) << "NOMBRE";
	cout << setw(45) << "DESCRIPCION";
	cout << setw(20) << "PRECIO VENTA";
	cout << setw(35) << "PRECIO COMPRA";
	cout << setw(55) << "FECHA DE ALTA" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

}
void Producto::MostrarEncabezadoYSuStock()
{
	system("cls");
	cout << setw(5) << "ID";
	cout << setw(15) << "NOMBRE";
	cout << setw(20) << "DESCRIPCION";
	cout << setw(20) << "PRECIO VENTA";
	cout << setw(35) << "CANTIDAD" << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
}
void Producto::MostrarInformacionProducto()
{
	if (_estado == true)
	{
		cout << setw(5) << GetId();
		cout << setw(15) << GetNombre();
		cout << setw(45) << GetDescripcion();
		cout << setw(20) << GetPrecioVenta();
		cout << setw(35) << GetPrecioCompra();
		cout << setw(55) << GetFecha().toString() << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}
void Producto::MostrarInformacionProductoSinID()
{
	if (_estado == true)
	{
		cout << setw(15) << GetNombre();
		cout << setw(45) << GetDescripcion();
		cout << setw(20) << GetPrecioVenta();
		cout << setw(35) << GetPrecioCompra();
		cout << setw(55) << GetFecha().toString() << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}
void Producto::MostrarProductoYSuStock()
{
	if (_estado == true)
	{
		cout << setw(5) << GetId();
		cout << setw(15) << GetNombre();
		cout << setw(20) << GetDescripcion();
		cout << setw(20) << GetPrecioVenta();
		cout << setw(35) << GetCantidad() << endl;
		cout << "-----------------------------------------------------------------------------------------" << endl;
	}
}

void Producto::SetId(int id) { _id = id; }
void Producto::SetCantidad(int cantidad) { _cantidad = cantidad; }
void Producto::SetNombre(const char* nombre) { strcpy_s(_nombre, nombre); }
void Producto::SetDescripcion(const char* desc) { strcpy_s(_descripcion, desc); }

void Producto::SetFecha() { _fecha.FechaActual(); }
void Producto::SetEstado(bool estado) { _estado = estado; }
void Producto::SetPrecioVenta(float precioVenta) { _precioVenta = precioVenta; }
void Producto::SetPrecioCompra(float precioCompra) { _precioCompra = precioCompra; }

int Producto::GetId() const { return _id; }
int Producto::GetCantidad() const { return _cantidad; }
char* Producto::GetNombre() { return _nombre; }
char* Producto::GetDescripcion() { return _descripcion; }

Fecha Producto::GetFecha() const { return _fecha; }
bool Producto::GetEstado() const { return _estado; }
float Producto::GetPrecioVenta() const { return _precioVenta; }
float Producto::GetPrecioCompra() const { return _precioCompra; }

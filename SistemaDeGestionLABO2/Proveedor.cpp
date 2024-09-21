#include "Proveedor.h"

void Proveedor::setTipo(const char* tipo) { strcpy_s(_tipo, tipo); }
const char* Proveedor::getTipo() const { return _tipo; }
void Proveedor::cargarProveedor()
{
	int cuil;
	char nombre[40], email[50], tipo[50];
	Fecha fechaAlta;

	cout << endl;
	cout << "CUIL: ";
	cin >> cuil;
	cin.ignore(); // Ignora el salto de linea pendiente despues de la entrada de cuil
	cout << endl;
	cout << "NOMBRE RAZON SOCIAL: ";
	cin.getline(nombre, sizeof(nombre));
	cout << endl;
	cout << "EMAIL: ";
	cin.getline(email, sizeof(email));
	cout << endl;
	cout << "TIPO: ";
	cin.getline(tipo, sizeof(tipo));
	cout << endl;
	setFechaAlta();
	cout << endl;

	setDni(cuil);
	setNombre(nombre);
	setEmail(email);
	setEstado(true);
	setTipo(tipo);
}
void Proveedor::mostrarProveedor()
{
	if (_estado == true)
	{
		cout << setw(5) << getId();
		cout << setw(15) << getDNI();
		cout << setw(20) << getNombre();
		cout << setw(35) << getEmail();
		cout << setw(45) << getTipo();
		cout << setw(35) << getFechaAlta().toString() << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}
void Proveedor::mostrarProveedorSinID()
{
	if (_estado == true)
	{
		cout << setw(15) << getDNI();
		cout << setw(20) << getNombre();
		cout << setw(35) << getEmail();
		cout << setw(45) << getTipo();
		cout << setw(35) << getFechaAlta().toString() << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}
void Proveedor::mostrarEncabezado()
{
	cout << left;
	cout << setw(5) << "ID";
	cout << setw(15) << "CUIL";
	cout << setw(20) << "RAZON SOCIAL";
	cout << setw(35) << "EMAIL";
	cout << setw(45) << "TIPO";
	cout << setw(35) << "FECHA DE ALTA" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void Proveedor::mostrarEncabezadoSinID()
{
	cout << left;
	cout << setw(15) << "DNI";
	cout << setw(20) << "RAZON SOCIAL";
	cout << setw(35) << "EMAIL";
	cout << setw(45) << "TIPO";
	cout << setw(35) << "FECHA DE ALTA" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
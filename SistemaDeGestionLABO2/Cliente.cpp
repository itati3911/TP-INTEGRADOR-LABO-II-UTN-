#include "Cliente.h"

void Cliente::setCategoria(bool categoria)
{
	if (categoria > 0)
	{
		_categoria = true;
	}

	if (categoria <= 0)
	{
		_categoria = false;
	}
}
bool Cliente::getCategoria() const { return _categoria; }
void Cliente::mostrarEncabezado()
{
	cout << left;
	cout << setw(5) << "ID";
	cout << setw(15) << "DNI";
	cout << setw(20) << "NOMBRES";
	cout << setw(20) << "APELLIDOS";
	cout << setw(35) << "EMAIL";
	cout << setw(45) << "CATEGORIA";
	cout << setw(35) << "FECHA DE ALTA" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void Cliente::mostrarEncabezadoSinID()
{
	cout << left;
	cout << setw(15) << "DNI";
	cout << setw(20) << "NOMBRES";
	cout << setw(20) << "APELLIDOS";
	cout << setw(35) << "EMAIL";
	cout << setw(45) << "CATEGORIA";
	cout << setw(35) << "FECHA DE ALTA" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void Cliente::cargarCliente()
{

	int categoria;
	this->Cargar();
	cout << "CATEGORIA (1-MAYORISTA / 0-MINORISTA): ";
	cin >> categoria;
	cout << endl;
	setCategoria(categoria);
}
void Cliente::mostrarCliente()
{
	if (_estado == true)
	{
		cout << setw(5) << getId();
		cout << setw(15) << getDNI();
		cout << setw(20) << getNombre();
		cout << setw(20) << getApellido();
		cout << setw(35) << getEmail();
		cout << setw(45) << (_categoria == 1 ? "MAYORISTA" : "MINORISTA");
		cout << setw(35) << getFechaAlta().toString() << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}
void Cliente::mostrarClienteSinID()
{
	if (_estado == true)
	{
		cout << setw(15) << getDNI();
		cout << setw(20) << getNombre();
		cout << setw(20) << getApellido();
		cout << setw(35) << getEmail();
		cout << setw(45) << (getCategoria() == true ? "MAYORISTA" : "MINORISTA"); // por que al poner negativo, devuelve mayorista
		cout << setw(35) << getFechaAlta().toString() << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}

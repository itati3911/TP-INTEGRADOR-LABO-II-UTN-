#include "Factura.h"

Factura::Factura()
{
	_id = -1;
	_idcliente = -1;
	strcpy_s(_formaDePago, "");
	_envio = false;
	_estado = false;
	_fecha = Fecha(0, 0, 0);
	_monto = 0;
	_tipo = 'z';
}

void Factura::setFormaDePago(const char* fp) { strcpy_s(_formaDePago, fp); }
void Factura::setIdCliente(int id) { _idcliente = id; }
void Factura::setEstado(bool estado) { _estado = estado; }
void Factura::setMonto(float monto) { _monto = monto; }
void Factura::setEnvio(bool e) { _envio = e; }
void Factura::setFechaActual() { _fecha.FechaActual(); }

void Factura::setFecha(int dia, int mes, int anio)
{
	_fecha.setDia(dia);
	_fecha.setMes(mes);
	_fecha.setAnio(anio);
}

void Factura::setId(int id) { _id = id; }

void Factura::setTipo(char tipo){_tipo = tipo;}

char* Factura::getFormaDePago() { return _formaDePago; }
bool Factura::getEnvio() { return _envio; }
int Factura::getIdCliente() { return _idcliente; }
Fecha Factura::getFecha() { return _fecha; }
float Factura::getMonto() { return _monto; }
int Factura::getId() { return _id; }
bool Factura::getEstado() { return _estado; }

char Factura::getTipo() {return _tipo;}

void Factura::MostrarEncabezado()
{
	cout << setw(15) << "ID DE FACTURA";
	cout << setw(15) << "ID DE CLIENTE";
	cout << setw(15) << "TIPO FACTURA";
	cout << setw(20) << "FORMA DE PAGO";
	cout << setw(20) << "ENVIO";
	cout << setw(15) << "MONTO";
	cout << setw(15) << "FECHA" << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
}
void Factura::Cargar(int idCliente, float monto)
{
	char formaDePago[10], tipo;
	bool envio;
	system("cls");

	cin.ignore();
	cout << "FORMA DE PAGO: ";
	cin.getline(formaDePago, sizeof(formaDePago));
	cout << endl;
	cout << "1-ENVIOS /// 0-RETIRO EN TIENDA : ";
	cin >> envio;
	cout << endl;
	cout << "TIPO DE FACTURA (A,B,C,D, ETC): ";
	cin >> tipo;

	setFormaDePago(formaDePago);
	setEnvio(envio);
	setIdCliente(idCliente);
	setMonto(monto);
	setFechaActual();
	setEstado(true);
	setTipo(tipo);
}
void Factura::Mostrar()
{
	char envio[25];

	if (getEstado() == true)
	{
		if (getEnvio() == true)
		{
			strcpy_s(envio, "ENVIO A DOMICILIO");
		}
		else
		{
			strcpy_s(envio, "RETIRO EN TIENDA");
		}

		cout << setw(15) << getId();
		cout << setw(15) << getIdCliente();
		cout << setw(15) << getTipo();
		cout << setw(20) << getFormaDePago();
		cout << setw(20) << envio;
		cout << setw(15) << getMonto();
		cout << setw(15) << _fecha.toString() << endl;
		cout << "----------------------------------------------------------------------------------------------------" << endl;

	}
}







#include "Persona.h"

Persona::Persona()
{
	_id = -1;
	_dni = 0;
	strcpy_s(_nombre, "");
	strcpy_s(_apellido, "");
	strcpy_s(_direccion, "");
	strcpy_s(_email, "");
	_fechaAlta = Fecha(0, 0, 0);
	_estado = true;
}


void Persona::setId(int id) { _id = id; }
void Persona::setDni(int d) { _dni = d; }
void Persona::setNombre(const char* nombre) { strcpy_s(_nombre, nombre); }
void Persona::setApellido(const char* apellido) { strcpy_s(_apellido, apellido); }
void Persona::setDomicilio(const char* domicilio) { strcpy_s(_direccion, domicilio); }
void Persona::setEmail(const char* email) { strcpy_s(_email, email); }

void Persona::setFechaAlta(){_fechaAlta.FechaActual();}

void Persona::setEstado(bool estado){_estado = estado;}

int Persona::getDNI() { return _dni; }
int Persona::getId() { return _id; }
char* Persona::getNombre() { return _nombre; }
char* Persona::getApellido() { return _apellido; }
char* Persona::getDomicilio() { return _direccion; }
char* Persona::getEmail() { return _email; }
Fecha Persona::getFechaAlta() { return _fechaAlta; }
bool Persona::getEstado(){return _estado;}


void Persona::Cargar()
{
	int dni;
	char nombre[40], apellido[40], direccion[100], email[50];
	Fecha fechaAlta;

	cout << endl;
	cout << "DNI: ";
	cin >> dni;
	cin.ignore();  // Ignora el salto de línea pendiente después de la entrada de dni
	cout << endl;
	cout << "NOMBRE: ";
	cin.getline(nombre, sizeof(nombre));
	cout << endl;
	cout << "APELLIDO: ";
	cin.getline(apellido, sizeof(apellido));
	cout << endl;
	cout << "EMAIL: ";
	cin.getline(email, sizeof(email));
	cout << endl;
	cout << "DOMICILIO: ";
	cin.getline(direccion, sizeof(direccion));
	cout << endl;
	setFechaAlta();
	cout << endl;

	setDni(dni);
	setNombre(nombre);
	setApellido(apellido);
	setEmail(email);
	setDomicilio(direccion);
	setEstado(true);
}

void Persona::Mostrar()
{
	if (_estado == true)
	{
		cout << setw(5) << getId();
		cout << setw(15) << getDNI();
		cout << setw(20) << getNombre();
		cout << setw(20) << getApellido();
		cout << setw(35) << getEmail();
		cout << setw(45) << getDomicilio();
		cout << setw(55) << getFechaAlta().toString() << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}

void Persona::Mostrar2()
{
	if (_estado == true)
	{
		cout << setw(15) << getDNI();
		cout << setw(20) << getNombre();
		cout << setw(20) << getApellido();
		cout << setw(35) << getEmail();
		cout << setw(45) << getDomicilio();
		cout << setw(55) << getFechaAlta().toString() << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}

	/*int i;
	mostrarEncabezado();
	for (int i = 0; i < 1; i++) {
		mostrarContenido();
	}*/
	cout << endl;
}

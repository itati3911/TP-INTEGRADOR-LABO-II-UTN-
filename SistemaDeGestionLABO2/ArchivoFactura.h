#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

#include "Factura.h"

class Factura;

class ArchivoFactura {
public:
    ArchivoFactura(const char* n);

	int ObtenerUltimoIdFactura() const;
	bool AltaFactura(Factura reg);
	bool BajaFactura(int pos);
	// bool ModificarFactura(Factura reg, int pos);
	bool ListarFactura(Factura reg) const;
	// bool sobreEscribirRegistro(Factura reg, int pos);
	int BuscarPosicion(Factura reg);
	Factura BuscarFactura(int n) const;
	float listarReporteCaja(Fecha fecha);
    
private:
    char _nombreArchivo[30];
};


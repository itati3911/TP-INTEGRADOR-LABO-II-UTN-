#pragma once
#include <iostream>
#include <cstdio>
#include "Cliente.h"
#include "Proveedor.h"
#include "Producto.h"

using namespace std;

class Backup {
public:
    
    Backup();// Constructor
    void backupClientes();
    void backupProveedores();
    void backupProductos();
};


void mostrarBKS(const std::string& archivoBinario, const std::string& nombreArchivoCSV, const std::string& encabezados, void (*exportarDatos)(FILE*, FILE*));
void DatosClientesBackup(FILE* archivoEntrada, FILE* archivoCSV);
void DatosProductoBackup(FILE* archivoEntrada, FILE* archivoCSV);
void DatosProveedorBackup(FILE* archivoEntrada, FILE* archivoCSV);


void mostrarRestauracionBK();
void restaurarBackup(const string& nombreArchivo, const string& nombreArchivoRestaurado);

void mostrarClientesBackup();
void mostrarProductosBackup();
void mostrarProveedoresBackup();





    
#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include "Cliente.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Usuarios.h"

void exportarACSV(const std::string& archivoBinario, const std::string& nombreArchivoCSV, const std::string& encabezados, void (*exportarDatos)(FILE*, FILE*));
void exportarDatosCliente(FILE* archivoEntrada, FILE* archivoCSV);
void exportarDatosProducto(FILE* archivoEntrada, FILE* archivoCSV);
void exportarDatosProveedor(FILE* archivoEntrada, FILE* archivoCSV);
void exportarDatosUsuario(FILE* archivoEntrada, FILE* archivoCSV);

void exportarClientesACSV();
void exportarProductosACSV();
void exportarProveedoresACSV();
void exportarUsuariosACSV();


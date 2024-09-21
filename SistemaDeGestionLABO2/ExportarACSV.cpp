#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include "ExportarACSV.h"

using namespace std;


void exportarACSV(const std::string& archivoBinario, const std::string& nombreArchivoCSV, const std::string& encabezados, void (*exportarDatos)(FILE*, FILE*)) {
    FILE* archivoEntrada = fopen(archivoBinario.c_str(), "rb");
    if (!archivoEntrada) {
        cout << "Error al abrir el archivo " << archivoBinario << endl;
        return;
    }

    FILE* archivoCSV = fopen(nombreArchivoCSV.c_str(), "wb");
    if (!archivoCSV) {
        cout << "Error al abrir el archivo " << nombreArchivoCSV << endl;
        fclose(archivoEntrada);
        return;
    }

    fprintf(archivoCSV, "%s\n", encabezados.c_str());

    exportarDatos(archivoEntrada, archivoCSV);

    fclose(archivoEntrada);
    fclose(archivoCSV);

    cout << "Datos exportados correctamente a " << nombreArchivoCSV << endl;

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();

}

void exportarDatosCliente(FILE* archivoEntrada, FILE* archivoCSV) {
    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, archivoEntrada) == 1) {
        if (cliente.getEstado()) {
            fprintf(archivoCSV, "%d,%s,%s,%s,%d\n",
                cliente.getId(),
                cliente.getApellido(),
                cliente.getNombre(),
                cliente.getDomicilio(),
                cliente.getDNI());
        }
    }
}

void exportarClientesACSV() {
    exportarACSV("Clientes.dat", "Clientes.csv", "id,apellido,nombre,domicilio,codpostal", exportarDatosCliente);
}

void exportarDatosProducto(FILE* archivoEntrada, FILE* archivoCSV) {
    Producto producto;
    while (fread(&producto, sizeof(Producto), 1, archivoEntrada) == 1) {
        if (producto.GetEstado()) {
            fprintf(archivoCSV, "%d,%s,%s,%.2f,%.2f\n",
                producto.GetId(),
                producto.GetNombre(),
                producto.GetDescripcion(),
                producto.GetPrecioVenta(),   
                producto.GetPrecioCompra());
        }
    }
}

void exportarProductosACSV() {
    exportarACSV("Productos.dat", "Productos.csv", "id,nombre,descripcion,precioVenta,precioCompra", exportarDatosProducto);
}

void exportarDatosProveedor(FILE* archivoEntrada, FILE* archivoCSV) {
    Proveedor proveedor;
    while (fread(&proveedor, sizeof(Proveedor), 1, archivoEntrada) == 1) {
        if (proveedor.getEstado()) {
            fprintf(archivoCSV, "%d,%s,%s,%s,%d\n",
                proveedor.getId(),
                proveedor.getApellido(),
                proveedor.getNombre(),
                proveedor.getDomicilio(),
                proveedor.getDNI());
        }
    }
}

void exportarProveedoresACSV() {
    exportarACSV("Proveedores.dat", "Proveedores.csv", "id,apellido,nombre,domicilio,codpostal", exportarDatosProveedor);
}

void exportarDatosUsuario(FILE* archivoEntrada, FILE* archivoCSV) {
    Usuarios usuario;
    while (fread(&usuario, sizeof(Usuarios), 1, archivoEntrada) == 1) {
        if (usuario.getEstado()) {
            fprintf(archivoCSV, "%d,%s,%s\n",
                usuario.GetId(),
                usuario.GetNombre(),
                usuario.GetPassw());
        }
    }
}

void exportarUsuariosACSV() {
    exportarACSV("Usuarios.dat", "Usuarios.csv", "id,usuario,passw", exportarDatosUsuario);
}

//#include "ExportarACSV.h"

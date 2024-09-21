#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include "Cliente.h"
#include "Proveedor.h"
#include "Producto.h"
#include "Backup.h"
#include "Menu.h"

using namespace std;


///*********************************************************************************************************
/// METODOS PARA HACER BACKUP DE LOS ARCHIVOS CREADOS. SOLO GUARDA LOS ESTADOS ACTIVOS EN EL ARCHIVO NUEVO
///*********************************************************************************************************

//CONSTRUCTOR DE BACKUP
Backup::Backup() {}


//PARA CLIENTES.DAT
void Backup::backupClientes() {
    FILE* archivoEntrada = fopen("Clientes.dat", "rb");//ABRO EN MODO LECTURA EL BINARIO ORIGEN
    if (!archivoEntrada) {//VALIDACION
        cout << "Error al abrir el archivo Clientes.dat" << endl;
        return;
    }

    FILE* archivoSalida = fopen("ClientesBackup.dat", "wb");//ABRO EN MODO ESCRITURA EL BINARIO BACKUP
    if (!archivoSalida) {//VALIDACION
        cout << "Error al abrir el archivo ClientesBackup.dat" << endl;
        fclose(archivoEntrada);
        return;
    }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, archivoEntrada) == 1) {//LEO EL ARCHIVO, SI EL ESTADO DEL REGISTRO ES ACTIVO LO COPIO AL BACKUP
        if (cliente.getEstado()) {
            fwrite(&cliente, sizeof(Cliente), 1, archivoSalida);
        }
    }

    fclose(archivoEntrada);//CIERRO AMBOS
    fclose(archivoSalida);

    cout << "Backup de clientes completado exitosamente." << endl;//MENSAJE DE SALIDA DE EXITO
    cout << "Archivo de backup: 'ClientesBackup.dat'" << endl;
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}


//PARA PROVEEDORES.DAT
void Backup::backupProveedores() {
    FILE* archivoEntrada = fopen("Proveedores.dat", "rb");
    if (!archivoEntrada) {
        cout << "Error al abrir el archivo Proveedores.dat" << endl;
        return;
    }

    FILE* archivoSalida = fopen("ProveedoresBackup.dat", "wb");
    if (!archivoSalida) {
        cout << "Error al abrir el archivo ProveedoresBackup.dat" << endl;
        fclose(archivoEntrada);
        return;
    }

    Proveedor proveedor;
    while (fread(&proveedor, sizeof(Proveedor), 1, archivoEntrada) == 1) {
        if (proveedor.getEstado()) {
            fwrite(&proveedor, sizeof(Proveedor), 1, archivoSalida);
        }
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);

    cout << "Backup de proveedores completado exitosamente." << endl;
    cout << "Archivo de backup: 'ProveedoresBackup.dat'" << endl;
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}


//PARA PRODUCTOS.DAT
void Backup::backupProductos() {
    FILE* archivoEntrada = fopen("Productos.dat", "rb");
    if (!archivoEntrada) {
        cout << "Error al abrir el archivo Productos.dat" << endl;
        return;
    }

    FILE* archivoSalida = fopen("ProductosBackup.dat", "wb");
    if (!archivoSalida) {
        cout << "Error al abrir el archivo ProductosBackup.dat" << endl;
        fclose(archivoEntrada);
        return;
    }

    Producto producto;
    while (fread(&producto, sizeof(Producto), 1, archivoEntrada) == 1) {
        if (producto.GetEstado()) {
            fwrite(&producto, sizeof(Producto), 1, archivoSalida);
        }
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);

    cout << "Backup de productos completado exitosamente." << endl;
    cout << "Archivo de backup: 'ProductosBackup.dat'" << endl;
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}


//***************************************************************************************************************
//FX MOSTRAR BKS
//***************************************************************************************************************
void mostrarBKS(const std::string& archivoBinario, const std::string& nombreArchivoCSV, const std::string& encabezados, void (*exportarDatos)(FILE*, FILE*)) {
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

//********************************************************************
//clientes

void DatosClientesBackup(FILE* archivoEntrada, FILE* archivoCSV) {
    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, archivoEntrada) == 1) {
       
            fprintf(archivoCSV, "%d,%s,%s,%s,%d\n",
                cliente.getId(),
                cliente.getNombre(),
                cliente.getApellido(),
                cliente.getCategoria(),
                cliente.getDNI());
        
    }
}

void mostrarClientesBackup() {
    mostrarBKS("ClientesBackup.dat", "ClientesBackup.csv", "id,apellido,nombre,domicilio,codpostal", DatosClientesBackup);
}

//************************************************************************
//productos

void DatosProductoBackup(FILE* archivoEntrada, FILE* archivoCSV) {
    Producto producto;
    while (fread(&producto, sizeof(Producto), 1, archivoEntrada) == 1) {
        
            fprintf(archivoCSV, "%d,%s,%s,%.2f,%.2f\n",
                producto.GetId(),
                producto.GetNombre(),
                producto.GetDescripcion(),
                producto.GetPrecioVenta(),
                producto.GetCantidad());
    }
}

void mostrarProductosBackup() {
    mostrarBKS("ProductosBackup.dat", "ProductosBackup.csv", "id,nombre,descripcion,precioVenta,precioCompra", DatosProductoBackup);
}

//************************************************************************
//proveedores

void DatosProveedorBackup(FILE* archivoEntrada, FILE* archivoCSV) {
    Proveedor proveedor;
    while (fread(&proveedor, sizeof(Proveedor), 1, archivoEntrada) == 1) {
       
            fprintf(archivoCSV, "%d,%s,%s,%s,%d\n",
                proveedor.getId(),
                proveedor.getNombre(),
                proveedor.getTipo(),
                proveedor.getEmail(),
                proveedor.getDNI());
       
    }
}

void mostrarProveedoresBackup() {
    mostrarBKS("ProveedoresBackup.dat", "ProveedoresBackup.csv", "id,apellido,nombre,domicilio,codpostal", DatosProveedorBackup);
}

//************************************************************************
//

//***********************************************************************
//RESTAURACION DE BACKUP
//***********************************************************************

void restaurarBackup(const string& nombreArchivo, const string& nombreArchivoRestaurado) {
    FILE* archivoBackup = fopen(nombreArchivo.c_str(), "rb"); // Abro el archivo de backup modo lectura

    if (!archivoBackup) {
        cout << "Error al abrir el archivo de backup" << endl;
        return;
    }

    FILE* archivoRestaurado = fopen(nombreArchivoRestaurado.c_str(), "wb"); // Abro un archivo nuevo para escribir los datos del backup

    if (!archivoRestaurado) {
        cout << "Error al crear el archivo restaurado" << endl;
        fclose(archivoBackup);
        return;
    }

    char bloque[1024];
    size_t bloqueDeLectura;

    while ((bloqueDeLectura = fread(bloque, 1, sizeof(bloque), archivoBackup)) > 0) {
        fwrite(bloque, 1, bloqueDeLectura, archivoRestaurado);
    }

    fclose(archivoBackup);
    fclose(archivoRestaurado);

    cout << "Backup restaurado con exito: " << nombreArchivoRestaurado << endl;
    system("pause");
}



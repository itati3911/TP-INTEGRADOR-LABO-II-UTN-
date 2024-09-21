#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

#include "Cliente.h"
#include "ArchivosClientes.h"
#include "Producto.h"
#include "ArchivosManager.h"

class DetalleFactura {
public:
    DetalleFactura();

    // Getters
    int getIdFactura() const;
    int getCantidad() const;
    float getMontoTotal() const;
    Producto getProducto() const;
    bool getEstado() const;

    // Setters
    void setIdFactura(int idFactura);
    void setCantidad(int cantidad);
    void setMontoTotal();
    void setProducto(Producto producto);
    void setEstado(bool estado);

    // Métodos
    void mostrarDetalle();
    void cargarFactura(int idFactura, Producto producto, int cantidad);
    void mostrarEncabezado();


private:
    int _idFactura;
    int _cantidad;
    float _montoTotal;
    Producto _producto;
    bool _estado;
};


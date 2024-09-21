#include "ArchivoFactura.h"

ArchivoFactura::ArchivoFactura(const char* n) { strcpy_s(_nombreArchivo, n); }

int ArchivoFactura::ObtenerUltimoIdFactura() const
{
    int pos;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
        return -1;

    fseek(p, 0, SEEK_END);
    pos = ftell(p);
    int ultimoRegistro = pos - sizeof(Factura);
    fseek(p, ultimoRegistro, SEEK_SET);

    Factura reg;
    if (fread(&reg, sizeof(Factura), 1, p) != 1)
    {
        fclose(p);
        return -1;
    }

    fclose(p);
    return reg.getId();
}
bool ArchivoFactura::AltaFactura(Factura reg)
{
    //reg.setId(ObtenerUltimoIdFactura() + 1);
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr)
        return false;

    fwrite(&reg, sizeof(Factura), 1, p);
    fclose(p);
    return true;
}
bool ArchivoFactura::BajaFactura(int pos)
{
    Factura reg;
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == NULL)
    {
        return false;
    }

    fseek(p, sizeof(Factura) * pos, 0);
    fread(&reg, sizeof(Factura), 1, p);
    reg.setEstado(false);
    fwrite(&reg, sizeof(Factura), 1, p);
    fclose(p);
    return true;
}
bool ArchivoFactura::ListarFactura(Factura reg) const
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return false;
    }

    while (fread(&reg, sizeof(Factura), 1, p) == 1)
    {
        reg.Mostrar();
    }
    fclose(p);
    return true;
}
int ArchivoFactura::BuscarPosicion(Factura reg)
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return -1;
    }

    Factura aux;
    int i = 0;
    while (fread(&aux, sizeof(Factura), 1, p) == 1)
    {
        if (reg.getId() == aux.getId())
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
Factura ArchivoFactura::BuscarFactura(int n) const
{
    Factura reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return reg;
    }

    while (fread(&reg, sizeof(Factura), 1, p) == 1) {
        if (reg.getEstado()==true)
        {
            if (reg.getId()==n)
            {
                return reg;
            }
        }
    }
    fclose(p);
}

float ArchivoFactura::listarReporteCaja(Fecha fecha)
{
    Factura reg;
    float monto = 0;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return -1;
    }

    while (fread(&reg, sizeof(Factura), 1, p) == 1)
    {
        if (reg.getFecha() == fecha);
        {
            monto += reg.getMonto();
        }
    }
    fclose(p);
    return monto;
}

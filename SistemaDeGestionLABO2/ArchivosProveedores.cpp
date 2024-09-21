#include "ArchivosProveedores.h"
#include "Proveedor.h"
	
ArchivosProveedores::ArchivosProveedores(const char* n){ strcpy_s(_nombreArchivo, n); }

int ArchivosProveedores::ObtenerUltimoIdProveedor() const
{
    int pos;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
        return -1;

    fseek(p, 0, SEEK_END);
    pos = ftell(p);
    int ultimoRegistro = pos - sizeof(Proveedor);
    fseek(p, ultimoRegistro, SEEK_SET);

    Proveedor reg;
    if (fread(&reg, sizeof(Proveedor), 1, p) != 1)
    {
        fclose(p);
        return -1;
    }

    fclose(p);
    return reg.getId();
}
bool ArchivosProveedores::AltaProveedor(Proveedor reg)
{
    reg.setId(ObtenerUltimoIdProveedor() + 1);
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr)
        return false;

    fwrite(&reg, sizeof(Proveedor), 1, p);
    fclose(p);
    return true;
}
bool ArchivosProveedores::BajaProveedor(int id)
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return false;
    }
    int pos = BuscarProveedorXID(id, p);
    fclose(p);

    if (pos == -1)
    {
        cout << "NO SE ENCONTRO REGISTRO" << endl;
        return false;
    }
    Proveedor reg = BuscarProveedor(id);
    reg.mostrarProveedor();
    char opc;
    cout << "desea borrar el registro? (S/N)" << endl;
    cin >> opc;
    if (opc == 's' || opc == 'S')
    {
        reg.setEstado(false);
        bool quePaso = sobreEscribirRegistro(reg, pos);
        return quePaso;
    }
    return false;
}
bool ArchivosProveedores::ModificarProveedor(Proveedor reg, int pos)
{
    char opc;
    cout << "Desea sobre escribir el registro? (S/N)" << endl;
    cin >> opc;
    if (opc == 's' || opc == 'S')
    {
        bool quePaso = sobreEscribirRegistro(reg, pos);
        return quePaso;
    }
    return false;
}
bool ArchivosProveedores::ListarProveedor(Proveedor reg) const
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return false;
    }

    while (fread(&reg, sizeof(Proveedor), 1, p) == 1)
    {
        reg.mostrarProveedor();
    }
    fclose(p);
    return true;
}
bool ArchivosProveedores::sobreEscribirRegistro(Proveedor reg, int pos)
{
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Proveedor) * pos, 0);
    bool escribio = fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return escribio;
}
int ArchivosProveedores::BuscarProveedorXID(int id, FILE* p) const
{
    /*FILE* p = fopen(_nombreArchivo, "rb");
if (p == nullptr)
{
return -1;
}*/

    int i = 0;
    Proveedor reg;
    while (fread(&reg, sizeof(Proveedor), 1, p) == 1)
    {
        if (reg.getId() == id)
        {
            // fclose(p);
            return i;
        }
        i++;
    }
    // fclose(p);
    return -1;
}
int ArchivosProveedores::BuscarProveedorXDNI(int dni, FILE* p) const
{
    /*FILE* p = fopen(_nombreArchivo, "rb");
if (p == nullptr)
{
return -1;
}*/

    int i = 0;
    Proveedor reg;
    while (fread(&reg, sizeof(Proveedor), 1, p) == 1)
    {
        if (reg.getDNI() == dni)
        {
            // fclose(p);
            return i;
        }
        i++;
    }
    // fclose(p);
    return -1;
}
int ArchivosProveedores::BuscarPosicion(Proveedor reg)
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return -1;
    }

    Proveedor aux;
    int i = 0;
    while (fread(&aux, sizeof(Proveedor), 1, p) == 1)
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
Proveedor ArchivosProveedores::BuscarProveedor(int n) const
{
    Proveedor reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return reg;
    }
    int pos;

    if (n > 999999)
    {
        pos = BuscarProveedorXDNI(n, p);
    }
    else
    {
        pos = BuscarProveedorXID(n, p);
    }
    if (pos != -1)
    {
        fseek(p, sizeof(Proveedor) * pos, 0);
        fread(&reg, sizeof(Proveedor), 1, p);
        fclose(p);
        return reg;
    }
    fclose(p);
    return reg;
}

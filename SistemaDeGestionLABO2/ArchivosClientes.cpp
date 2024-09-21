#include "ArchivosClientes.h"
#include "Cliente.h"

ArchivosClientes::ArchivosClientes(const char* n) { strcpy_s(_nombreArchivo, n); }

int ArchivosClientes::ObtenerUltimoIdCliente() const
{
    int pos;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
        return -1;

    fseek(p, 0, SEEK_END);
    pos = ftell(p);
    int ultimoRegistro = pos - sizeof(Cliente);
    fseek(p, ultimoRegistro, SEEK_SET);

    Cliente reg;
    if (fread(&reg, sizeof(Cliente), 1, p) != 1)
    {
        fclose(p);
        return -1;
    }

    fclose(p);
    return reg.getId();
}
bool ArchivosClientes::AltaCliente(Cliente reg)
{
    reg.setId(ObtenerUltimoIdCliente() + 1);
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr)
        return false;

    fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return true;
}
bool ArchivosClientes::BajaCliente(int id)
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return false;
    }
    int pos = BuscarClienteXID(id, p);
    fclose(p);

    if (pos == -1)
    {
        cout << "NO SE ENCONTRO REGISTRO" << endl;
        return false;
    }
    Cliente reg = BuscarCliente(id);
    reg.mostrarCliente();
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
bool ArchivosClientes::ModificarCliente(Cliente reg, int pos)
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
bool ArchivosClientes::ListarCliente(Cliente reg) const
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return false;
    }

    while (fread(&reg, sizeof(Cliente), 1, p) == 1)
    {
        reg.mostrarCliente();
    }
    fclose(p);
    return true;
}
bool ArchivosClientes::sobreEscribirRegistro(Cliente reg, int pos)
{
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Cliente) * pos, 0);
    bool escribio = fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return escribio;
}
int ArchivosClientes::BuscarClienteXID(int id, FILE* p) const
{ /*FILE* p = fopen(_nombreArchivo, "rb");
if (p == nullptr)
{
return -1;
}*/

    int i = 0;
    Cliente reg;
    while (fread(&reg, sizeof(Cliente), 1, p) == 1)
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
int ArchivosClientes::BuscarCLienteXDNI(int dni, FILE* p) const
{ /*FILE* p = fopen(_nombreArchivo, "rb");
if (p == nullptr)
{
return -1;
}*/

    int i = 0;
    Cliente reg;
    while (fread(&reg, sizeof(Cliente), 1, p) == 1)
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
int ArchivosClientes::BuscarPosicion(Cliente reg)
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return -1;
    }

    Cliente aux;
    int i = 0;
    while (fread(&aux, sizeof(Cliente), 1, p) == 1)
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
Cliente ArchivosClientes::BuscarCliente(int n) const
{
    Cliente reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return reg;
    }
    int pos;

    if (n > 999999)
    {
        pos = BuscarCLienteXDNI(n, p);
    }
    else
    {
        pos = BuscarClienteXID(n, p);
    }
    if (pos != -1)
    {
        fseek(p, sizeof(Cliente) * pos, 0);
        fread(&reg, sizeof(Cliente), 1, p);
        fclose(p);
        return reg;
    }
    fclose(p);
    return reg;
}


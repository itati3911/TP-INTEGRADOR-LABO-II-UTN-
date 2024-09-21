#include "ArchivosManager.h"
#include "Usuarios.h"
#include "Producto.h"
#include "DetalleFactura.h"

ArchivosManager::ArchivosManager(const char* n) { strcpy_s(_nombreArchivo, n); }

// METODOS PARA USUARIOS
int ArchivosManager::ObtenerUltimoId() const
{
    int pos;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
        return -1;

    fseek(p, 0, SEEK_END);
    pos = ftell(p);
    int ultimoRegistro = pos - sizeof(Usuarios);
    fseek(p, ultimoRegistro, SEEK_SET);

    Usuarios reg;
    if (fread(&reg, sizeof(Usuarios), 1, p) != 1)
    {
        fclose(p);
        return -1;
    }

    fclose(p);
    return reg.GetId();
}
Usuarios ArchivosManager::BuscarUsuario(const char* usuario, const char* passw) const
{
    Usuarios reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        cout << "Error al abrir el archivo de usuarios." << endl;
        return reg;
    }

    while (fread(&reg, sizeof(Usuarios), 1, p) == 1)
    {
        if (reg.getEstado() == true && reg.verificarCredenciales(usuario, passw) == true)
        {
            fclose(p);
            return reg;
        }
    }
    fclose(p);
    reg.SetId(-1);
    return reg;
}
bool ArchivosManager::AltaUsuario(Usuarios reg)
{
    reg.SetId(ObtenerUltimoId() + 1);
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr)
        return false;

    fwrite(&reg, sizeof(Usuarios), 1, p);
    fclose(p);
    return true;
}
bool ArchivosManager::BajaUsuario(int id)
{
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == nullptr)
    {
        cerr << "Error al abrir el archivo de usuarios." << endl;
        return false;
    }

    Usuarios reg;
    int pos = -1;

    while (fread(&reg, sizeof(Usuarios), 1, p) == 1)
    {
        pos++;
        if (reg.getEstado() && reg.GetId() == id)
        {
            fseek(p, sizeof(Usuarios) * pos, SEEK_SET);

            reg.setEstado(false);

            fwrite(&reg, sizeof(Usuarios), 1, p);
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
bool ArchivosManager::ModificarUsuario(int id, const char* nuevoUsuario, const char* nuevaPassw)
{
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == nullptr)
    {
        cerr << "Error al abrir el archivo de usuarios." << endl;
        return false;
    }

    Usuarios reg;
    int pos = -1;

    while (fread(&reg, sizeof(Usuarios), 1, p) == 1)
    {
        pos++;
        if (reg.getEstado() && reg.GetId() == id)
        {
            fseek(p, sizeof(Usuarios) * pos, SEEK_SET);
            if (nuevoUsuario != nullptr)
            {
                cin.ignore();
                reg.cambiarUsuario(nuevoUsuario, nullptr);
                cout << endl;
            }
            if (nuevaPassw != nullptr)
            {
                reg.cambiarUsuario(nullptr, nuevaPassw);
                cout << endl;
            }
            fwrite(&reg, sizeof(Usuarios), 1, p);
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
bool ArchivosManager::ListarUsuarios(Usuarios reg)
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
        return false;

    while (fread(&reg, sizeof(Usuarios), 1, p) == 1)
    {
        if (reg.getEstado() == true)
        {
            reg.Mostar();
        }
    }
}

// METODOS PARA PRODUCTOS
int ArchivosManager::ObtenerUltimoIdProducto() const
{
    int pos;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
        return -1;

    fseek(p, 0, SEEK_END);
    pos = ftell(p);
    int ultimoRegistro = pos - sizeof(Producto);
    fseek(p, ultimoRegistro, SEEK_SET);

    Producto reg;
    if (fread(&reg, sizeof(Producto), 1, p) != 1)
    {
        fclose(p);
        return -1;
    }
    fclose(p);
    return reg.GetId();
}
bool ArchivosManager::AltaProducto(Producto reg)
{
    reg.SetId(ObtenerUltimoIdProducto() + 1);
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr)
        return false;

    fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return true;
}
bool ArchivosManager::BajaProducto(int id)
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return false;
    }

    int pos = BuscarProductoXID(id, p);
    fclose(p);

    if (pos == -1)
    {
        cout << "NO SE ENCONTRO REGISTRO" << endl;
        return false;
    }
    Producto reg = BuscarProducto(id);
    reg.MostrarInformacionProducto();
    char opc;
    cout << "Desea borrar el registro? (S/N)" << endl;
    cin >> opc;
    if (opc == 's' || opc == 'S')
    {
        reg.SetEstado(false);
        bool quePaso = sobreEscribirRegistroProducto(reg, pos);
        return quePaso;
    }
    return false;
}
bool ArchivosManager::ModificarProducto(Producto reg, int pos)
{
    char opc;
    cout << "Desea sobre escribir el registro? (S/N)" << endl;
    cin >> opc;
    if (opc == 's' || opc == 'S')
    {
        bool quePaso = sobreEscribirRegistroProducto(reg, pos);
        return quePaso;
    }
    return false;
}
bool ArchivosManager::ListarProducto(Producto reg) const
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return false;
    }

    while (fread(&reg, sizeof(Producto), 1, p) == 1)
    {
        reg.MostrarInformacionProducto();
    }
    fclose(p);
    return true;
}


// MEOTOD PARA STOCK
bool ArchivosManager::ListarStock(Producto reg) const
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return false;
    }

    while (fread(&reg, sizeof(Producto), 1, p) == 1)
    {
        reg.MostrarProductoYSuStock();
    }
    fclose(p);
    return true;
}
bool ArchivosManager::sobreEscribirRegistroProducto(Producto reg, int pos)
{
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Producto) * pos, 0);
    bool escribio = fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return escribio;
}
int ArchivosManager::BuscarProductoXID(int id, FILE* p) const
{
    int i = 0;
    Producto reg;
    while (fread(&reg, sizeof(Producto), 1, p) == 1)
    {
        if (reg.GetId() == id)
        {
            return i;
        }
        i++;
    }
    return -1;
}
int ArchivosManager::BuscarStockXID(int id, FILE* p) const
{
    int i = 0;
    Producto reg;
    while (fread(&reg, sizeof(Producto), 1, p) == 1)
    {
        if (reg.GetId() == id)
        {
            return i;
        }
        i++;
    }
    return -1;
}
int ArchivosManager::BuscarProductoXNombre(const char* nombre) const
{
    Producto reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return -1;
    }
    int pos = 0;

    while (fread(&reg, sizeof(Producto), 1, p) == 1)
    {
        if (strcmp(reg.GetNombre(), nombre) == 0)
        {
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}
int ArchivosManager::BuscarPosicion(Producto reg)
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return -1;
    }
    Producto aux;
    int i = 0;
    while (fread(&aux, sizeof(Producto), 1, p) == 1)
    {
        if (reg.GetId() == aux.GetId())
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
Producto ArchivosManager::BuscarProducto(int n) const
{
    Producto reg, regFalse;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return reg;
    }

    if (n != -1)
    {
        fseek(p, sizeof(Producto) * n, 0);
        fread(&reg, sizeof(Producto), 1, p);
        fclose(p);
        if (reg.GetEstado()==false)
        {
            return regFalse;
        }
        return reg;
    }
    fclose(p);
    return reg;
}
bool ArchivosManager::verificarStock(Producto reg, int cantidad)
{
    Producto aux;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return false;
    }
    while (fread(&aux, sizeof(Producto), 1, p) == 1) {
        if (reg.GetId() == aux.GetId())
        {
            if (aux.GetCantidad()<cantidad)
            {
                fclose(p);
                return false;
            }
            else {
                fclose(p);
                return true;
            }
        }
    }
    fclose(p);
    return false;
}
bool ArchivosManager::ajustarStock(Producto reg, int cantidad)
{
    Producto aux;
    int nuevaCantidad = 0, pos;
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == nullptr)
    {
        return false;
    }

    pos = BuscarProductoXID(reg.GetId(), p);
    if (reg.GetCantidad()> cantidad)
    {
    reg.SetCantidad(reg.GetCantidad() - cantidad);
    fseek(p, sizeof(Producto) * pos, 0);
    bool escribio = fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return escribio;
    }

    return false;
}
bool ArchivosManager::aumentarStock(int id, int cantidad)
{
    Producto aux;
    int i = 0;

    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return false;
    }

    while (fread(&aux, sizeof(Producto), 1, p) == 1){
    
        if (aux.GetId()==id)
        {
            cantidad += aux.GetCantidad();
            aux.SetCantidad(cantidad);
            break;
        }
        i++;
    }

    fclose(p);
    bool escribio = sobreEscribirRegistroProducto(aux, i);
    return escribio;
}


// METODOS PARA EL DETALLE
bool ArchivosManager::altaDetalle(DetalleFactura reg)
{
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr)
    {
        return false;
    }

    fwrite(&reg, sizeof(DetalleFactura), 1, p);
    fclose(p);
    return true;
}
bool ArchivosManager::bajaDetalle(int id)
{
    DetalleFactura reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return false;
    }
    while (fread(&reg, sizeof(DetalleFactura), 1, p) == 1)
    {
        if (reg.getIdFactura() == id)
        {
            reg.setEstado(false);
        }
    }
    return true;
}
bool ArchivosManager::ListarDetalle(DetalleFactura reg)
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return false;
    }

    while (fread(&reg, sizeof(DetalleFactura), 1, p) == 1)
    {
        reg.mostrarDetalle();
    }
    fclose(p);
    return true;
}



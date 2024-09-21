#include "Manager.h"

// METODOS PARA MANEJAR USUARIOS
void Manager::MostrarEncabezadoUsuario()
{
    cout << left;
    cout << setw(5) << "USUARIOS" << endl;
    cout << "--------------------------------";
}
bool Manager::entradaAlSistema()
{
    char inputUsuario[16];
    char inputPassw[16];

    cout << "Ingrese su usuario: ";
    cin >> inputUsuario;
    cout << endl;
    cout << "Ingrese su contrasenia: ";
    cin >> inputPassw;
    cout << endl;

    Usuarios aux(inputUsuario, inputPassw);
    setUsuarios(_reg.BuscarUsuario(inputUsuario, inputPassw));

    setConsoleSize(10, 60);
    if (_usuarios == aux)
    {
        system("cls");
        cout << "Inicio de sesion exitoso. Bienvenido!" << endl
            << endl;
        system("pause");
        return true;
    }

    else
    {
        system("cls");
        cout << "Inicio de sesion fallido. Credenciales incorrectas." << endl
            << endl;
        system("pause");
        return false;
    }
}
void Manager::setUsuarios(Usuarios usuario) { _usuarios = usuario; }
void Manager::AltaUsuarios()
{
    _usuarios.Cargar();
    bool cargo = _reg.AltaUsuario(_usuarios);
    if (cargo)
    {
        cout << "Usuario dado de alta con exito" << endl;
        system("pause");
    }
    else
    {
        cout << "ERROR AL DAR DE ALTA USUARIO" << endl;
    }
}
void Manager::BajaUsuario()
{
    system("cls");
    Usuarios aux;
    bool borro = false;
    char inputUsuario[16];
    char inputPassw[16];
    setConsoleSize(10, 60);
    cout << "Ingrese el usuario que desea borrar: ";
    cin >> inputUsuario;
    cout << endl;
    cout << "Ingrese su contrase�a: ";
    cin >> inputPassw;
    cout << endl;

    aux = _reg.BuscarUsuario(inputUsuario, inputPassw);

    if (aux.GetId() != -1)
    {
        setConsoleSize(10, 60);
        int opc;
        cout << "Se encontro usuario!" << " �Desea borrar?" << endl;
        cout << "1- SI" << endl;
        cout << "2- NO" << endl;
        cout << "Opcion elegida: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            system("cls");
            setConsoleSize(10, 60);
            borro = _reg.BajaUsuario(aux.GetId());

            if (borro)
            {
                system("cls");
                cout << "Usuario borrado" << endl;
                system("pause");
            }
            break;
        case 2:
            return;
            break;
        default:
            system("cls");
            setConsoleSize(10, 60);
            cout << "OPCION INVALIDA" << endl;
            system("pause");
            return;
            break;
        }
    }
    else
    {
        system("cls");
        setConsoleSize(10, 60);
        cout << "NO SE ENCUENTRA USUARIO EN SISTEMA" << endl;
        system("pause");
    }
}
void Manager::MoidificarUsuarios()
{
    system("cls");
    Usuarios aux;
    bool modifico = false;
    char inputUsuario[16];
    char inputPassw[16];
    char NuevoUsuario[16];
    char NuevaPassw[16];
    setConsoleSize(10, 60);
    cout << "Ingrese el usuario que desea modificar: ";
    cin >> inputUsuario;
    cout << endl;
    cout << "Ingrese su contrase�a: ";
    cin >> inputPassw;
    cout << endl;

    aux = _reg.BuscarUsuario(inputUsuario, inputPassw);

    if (aux.GetId() != -1)
    {
        setConsoleSize(10, 60);
        int opc;
        cout << "Se encontro usuario!" << " �Que desea cambiar?" << endl;
        cout << "1- Usuario" << endl;
        cout << "2- Passw" << endl;
        cout << "Opcion elegida: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            system("cls");
            setConsoleSize(10, 60);
            cout << "INGRESE NUEVO USUARIO: " << endl;
            cin >> NuevoUsuario;
            modifico = _reg.ModificarUsuario(aux.GetId(), NuevoUsuario, nullptr);
            if (modifico)
            {
                system("cls");
                cout << "Usuario cambiado con exito" << endl;
                system("pause");
            }
            break;
        case 2:
            system("cls");
            setConsoleSize(10, 60);
            cout << "INGRESE NUEVA PASSW: " << endl;
            cin >> NuevaPassw;
            modifico = _reg.ModificarUsuario(aux.GetId(), nullptr, NuevaPassw);
            if (modifico)
            {
                system("cls");
                cout << "Passw cambiada con exito" << endl;
                system("pause");
            }
            break;
        default:
            system("cls");
            setConsoleSize(10, 60);
            cout << "OPCION INVALIDA" << endl;
            system("pause");
            return;
            break;
        }
    }
    else
    {
        system("cls");
        setConsoleSize(10, 60);
        cout << "NO SE ENCUENTRA USUARIO EN SISTEMA" << endl;
        system("pause");
    }
}
void Manager::listarUsuarios()
{
    system("cls");
    if (_reg.ListarUsuarios(_usuarios))
    {
        _reg.ListarUsuarios(_usuarios);
    }
    system("pause");
}
bool Manager::permisosAdmin(){
    Usuarios admin("admin", "admin");
    if (_usuarios == admin)
    {
        return true;
    }
    return false;
}

// METODOS PARA MANEJAR PRODUCTOS
void Manager::MostrarEncabezadoProductos() { _producto.MostrarEncabezado(); }
void Manager::MostrarEncabezadoProductosSinID() { _producto.MostrarEncabezadoSinID(); }
void Manager::mostrarEncabezado2() { _producto.MostrarEncabezadoYSuStock(); }
void Manager::mostrarEncabezado2SinID() { _producto.MostrarInformacionProductoSinID(); }
void Manager::AltaProducto()
{
    system("cls");
    cout << "INGRESE LOS DATOS DEL NUEVO PRODUCTO:" << endl;
    int id = _regProductos.ObtenerUltimoIdProducto();
    _producto.SetId(id);
    _producto.CargarProducto();
    system("cls");
    cout << "Corrobore los datos:" << endl;
    setConsoleSize(20, 170);
    MostrarEncabezadoProductosSinID();
    _producto.MostrarInformacionProductoSinID();
    char opc;
    cout << endl
        << endl;
    cout << "DATOS CORRECTOS? (S/N)" << endl;
    cin >> opc;
    if (opc == 's' || opc == 'S')
    {
        bool alta;
        alta = _regProductos.AltaProducto(_producto);
        system("cls");
        if (alta)
            cout << "PRODUCTO CARGADO CON EXITO" << endl;
        system("pause");
        return;
    }
    else
    {
        system("cls");
        cout << "DESEA CARGAR DE NUEVO EL PRODUCTO? (S/N)" << endl;
        char opc2;
        cin >> opc2;
        if (opc2 == 's' || opc2 == 'S')
        {
            AltaProducto();
            return;
        }
        else
        {
            return;
        }
    }
}
void Manager::BajaProducto()
{
    system("cls");
    Producto aux;
    bool borro = false;
    int id;
    setConsoleSize(10, 60);
    cout << "Ingrese el ID: ";
    cin >> id;
    cout << endl;

    aux = _regProductos.BuscarProducto(id);

    if (aux.GetId() != -1)
    {
        setConsoleSize(20, 170);
        int opc;
        cout << endl;
        MostrarEncabezadoProductos();
        aux.MostrarInformacionProducto();
        cout << endl;
        cout << "Se encontro Producto!" << "Desea borrar?" << endl;
        cout << "1- SI" << endl;
        cout << "2- NO" << endl;
        cout << "Opcion elegida: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            system("cls");
            borro = _regProductos.BajaProducto(aux.GetId());
            system("pause");
            if (borro)
            {
                system("cls");
                setConsoleSize(10, 60);
                cout << "Producto borrado" << endl;
                system("pause");
            }
            break;
        case 2:
            return;
            break;
        default:
            system("cls");
            setConsoleSize(10, 60);
            cout << "OPCION INVALIDA" << endl;
            system("pause");
            return;
            break;
        }
    }
    else
    {
        system("cls");
        setConsoleSize(10, 60);
        cout << "NO SE ENCUENTRA CLIENTE EN SISTEMA" << endl;
        system("pause");
    }
}
void Manager::MoidificarProducto()
{
    system("cls");
    Producto aux;
    bool modifico = false;
    char nombre[40], desc[100];
    float precioVenta, precioCompra;
    int id;

    setConsoleSize(10, 60);
    cout << "Ingrese el ID del producto a modificar: ";
    cin >> id;
    cout << endl;

    aux = _regProductos.BuscarProducto(id);

    if (aux.GetId() != -1)
    {

        while (true)
        {
            system("cls");
            setConsoleSize(20, 170);
            MostrarEncabezadoProductos();
            aux.MostrarInformacionProducto();
            cout << endl
                << endl;
            int opc, pos;
            pos = _regProductos.BuscarPosicion(aux);
            cout << "Se encontro Producto!" << "Que desea cambiar?" << endl;
            cout << "1- Nombre" << endl;
            cout << "2- Descripcion" << endl;
            cout << "3- Precio de venta" << endl;
            cout << "4- Precio de compra" << endl;
            cout << "0- Cancelar" << endl;
            cout << "Opcion elegida: ";
            cin >> opc;
            switch (opc)
            {
            case 1:
                system("cls");
                setConsoleSize(10, 60);
                cout << "INGRESE NUEVO NOMBRE: " << endl;
                cin.ignore();
                cin.getline(nombre, sizeof(nombre));
                aux.SetNombre(nombre);

                modifico = _regProductos.ModificarProducto(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "NOMBRE DE PRODUCTO CAMBIADO CON EXITO" << endl;
                    system("pause");
                }
                else
                {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                return;
                break;
            case 2:
                system("cls");
                setConsoleSize(10, 60);
                cout << "INGRESE NUEVA DESCRIPCION: " << endl;

                cin.ignore();
                cin.getline(desc, sizeof(desc));
                aux.SetDescripcion(desc);

                modifico = _regProductos.ModificarProducto(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "DESCRIPCION DE PRODUCTO CAMBIADO CON EXITO" << endl;
                    system("pause");
                }
                else
                {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                return;
                break;
            case 3:
                system("cls");
                setConsoleSize(10, 60);
                cout << "INGRESE NUEVO PRECIO DE VENTA: " << endl;

                cin >> precioVenta;
                aux.SetPrecioVenta(precioVenta);

                modifico = _regProductos.ModificarProducto(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "PRECIO DE VENTA CAMBIADO CON EXITO" << endl;
                    system("pause");
                }
                else
                {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                return;
                break;
            case 4:
                system("cls");
                setConsoleSize(10, 60);
                cout << "INGRESE NUEVO PRECIO DE COMPRA: " << endl;

                cin >> precioCompra;
                aux.SetPrecioCompra(precioCompra);

                modifico = _regProductos.ModificarProducto(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "PRECIO DE COMPRA CAMBIADO CON EXITO" << endl;
                    system("pause");
                }
                else
                {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                break;
            case 0:
                return;
                break;
            default:
                system("cls");
                setConsoleSize(10, 60);
                cout << "OPCION INVALIDA" << endl;
                system("pause");
                break;
            }
        }
    }
    else
    {
        system("cls");
        setConsoleSize(10, 60);
        cout << "NO SE ENCUENTRA PRODUCTO EN SISTEMA" << endl;
        system("pause");
    }
}
void Manager::listarProducto()
{
    Producto producto;
    system("cls");
    setConsoleSize(25, 170);
    MostrarEncabezadoProductos();
    _regProductos.ListarProducto(producto);
    system("pause");
}
void Manager::BuscarProductoXID()
{
    Producto producto;
    system("cls");
    setConsoleSize(60, 170);
    cout << "INGRESE ID DEL PRODUCTO:" << endl;
    int id;
    cin >> id;

    producto = _regProductos.BuscarProducto(id);
    if (producto.GetId() != -1)
    {
        MostrarEncabezadoProductos();
        producto.MostrarInformacionProducto();
        system("pause");
    }
    else
    {
        system("cls");
        cout << "NO SE ENCONTRO PRODUCTO, VUELVA A INTENTA" << endl;
        system("pause");
    }
}
void Manager::BuscarProductoXNombre()
{
    Producto producto;
    system("cls");
    setConsoleSize(25, 170);
    cout << "INGRESE NOMBRE DEL PRODUCTO (DEBE SER EXACTO):" << endl;
    int pos;
    char nombre[40] = {};
    cin.ignore();
    cin.getline(nombre, sizeof(nombre));
    pos = _regProductos.BuscarProductoXNombre(nombre);
    if (pos != -1)
    {
        producto = _regProductos.BuscarProducto(pos);
        MostrarEncabezadoProductos();
        producto.MostrarInformacionProducto();
        system("pause");
    }
    else
    {
        system("cls");
        cout << "NO SE ENCONTRO PRODUCTO, VUELVA A INTENTA" << endl;
        system("pause");
    }
}

void Manager::CargarCompra() // corregir
{
    int id, cantidad;
    Producto producto;
    bool continuar = true;

    while (continuar)
    {
        system("cls");
        setConsoleSize(25, 65);
        cout << "INGRESE ID DE PRODUCTO A COMPRAR: ";
        cin >> id;
        producto.SetId(id);
        int pos = _regProductos.BuscarPosicion(producto);
        if (pos == -1)
        {
            cout << "NO HAY PRODUCTO EN BASE DE DATOS. DESEA CONTINUAR? (1-SI / 0-NO) ";
            cin >> continuar;
        }
        else
        {

        cout << "INGRESE CANTIDAD A COMPRAR: ";
        cin >> cantidad;
        _regProductos.aumentarStock(id, cantidad);
        system("cls");
        cout << endl;
        cout << "STOCK ACTUALIZADO. DESEA CARGAR MAS? (1-SI / 0-NO) ";
        cin >> continuar;
        }
    }
}

void Manager::ListarStock()
{
    Producto producto;
    system("cls");
    setConsoleSize(25, 90);
    _producto.MostrarEncabezadoYSuStock();
    _regProductos.ListarStock(producto);
    system("pause");
}
void Manager::BuscarStock()
{
    Producto producto;
    system("cls");
    setConsoleSize(25, 90);
    cout << "INGRESE ID DEL PRODUCTO:" << endl;
    int id;
    cin >> id;

    producto = _regProductos.BuscarProducto(id);
    if (producto.GetId() != -1)
    {
        producto.MostrarEncabezadoYSuStock();
        producto.MostrarProductoYSuStock();
        system("pause");
    }
    else
    {
        setConsoleSize(25, 85);
        system("cls");
        cout << "NO SE ENCONTRO PRODUCTO, VUELVA A INTENTA" << endl;
        system("pause");
    }
}



//METODOS PARA MANEJAR CLIENTES
void Manager::AltaCliente()
{
    system("cls");
    cout << "INGRESE LOS DATOS DEL NUEVO CLIENTE:" << endl << endl;
    Cliente cliente;
    int id = _regClientes.ObtenerUltimoIdCliente();
    cliente.setId(id);
    cliente.cargarCliente();
    system("cls");
    cout << "Corrobore los datos:" << endl;
    setConsoleSize(20, 170);
    cliente.mostrarEncabezadoSinID();
    cliente.mostrarClienteSinID();
    char opc;
    cout << endl << endl;
    cout << "DATOS CORRECTOS? (S/N)" << endl;
    cin >> opc;
    if (opc == 's' || opc == 'S')
    {
        bool alta;
        alta = _regClientes.AltaCliente(cliente);
        system("cls");
        if (alta)  cout << "CLIENTE CARGADO CON EXITO" << endl;
        system("pause");
        return;
    }
    else {
        system("cls");
        cout << "DESEA CARGAR DE NUEVO EL CLIENTE? (S/N)" << endl;
        char opc2;
        cin >> opc2;
        if (opc2 == 's' || opc2 == 'S')
        {
            AltaCliente();
            return;
        }
        else
        {
            return;
        }
    }
}
void Manager::BajaCliente()
{
    system("cls");
    Cliente aux;
    bool borro = false;
    int ID_DNI;
    setConsoleSize(10, 60);
    cout << "Ingrese el ID o DNI del cliente a borrar: ";
    cin >> ID_DNI;
    cout << endl;

    aux = _regClientes.BuscarCliente(ID_DNI);

    if (aux.getId() != -1)
    {
        setConsoleSize(20, 170);
        int opc;
        cout << endl;
        aux.mostrarEncabezado();
        aux.mostrarCliente();
        cout << endl;
        cout << "Se encontro cliente!" << "Desea borrar?" << endl;
        cout << "1- SI" << endl;
        cout << "2- NO" << endl;
        cout << "Opcion elegida: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            system("cls");
            borro = _regClientes.BajaCliente(aux.getId());

            if (borro)
            {
                system("cls");
                setConsoleSize(10, 60);
                cout << "Cliente borrado" << endl;
                system("pause");
            }
            break;
        case 2:
            return;
            break;
        default:
            system("cls");
            setConsoleSize(10, 60);
            cout << "OPCION INVALIDA" << endl;
            system("pause");
            return;
            break;
        }
    }
    else
    {
        system("cls");
        setConsoleSize(10, 60);
        cout << "NO SE ENCUENTRA CLIENTE EN SISTEMA" << endl;
        system("pause");
    }
}
void Manager::ModificarCliente()
{
    system("cls");
    Cliente aux;
    bool modifico = false, categoria;
    char nombre[40], apellido[40], email[50];
    int id;

    setConsoleSize(10, 60);
    cout << "Ingrese el ID o DNI del cliente a modificar: ";
    cin >> id;
    cout << endl;

    aux = _regClientes.BuscarCliente(id);

    if (aux.getId() != -1)
    {

        while (true)
        {
            system("cls");
            setConsoleSize(20, 170);
            aux.mostrarEncabezado();
            aux.mostrarCliente();
            cout << endl << endl;
            int opc, pos;
            pos = _regClientes.BuscarPosicion(aux);
            cout << "Se encontro Cliente!" << " �Que desea cambiar?" << endl;
            cout << "1- Nombre" << endl;
            cout << "2- Apellido" << endl;
            cout << "3- Categoria" << endl;
            cout << "4- Email" << endl;
            cout << "0- Cancelar" << endl;
            cout << "Opcion elegida: ";
            cin >> opc;
            switch (opc)
            {
            case 1:
                system("cls");
                setConsoleSize(10, 60);
                cout << "INGRESE NUEVO NOMBRE: " << endl;

                cin.ignore();
                cin.getline(nombre, sizeof(nombre));
                aux.setNombre(nombre);

                modifico = _regClientes.ModificarCliente(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "NOMBRE DE CLIENTE CAMBIADO CON EXITO" << endl;
                    system("pause");
                }
                else {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                return;
                break;
            case 2:
                system("cls");
                setConsoleSize(10, 60);
                cout << "INGRESE NUEVO APELLIDO: " << endl;

                cin.ignore();
                cin.getline(apellido, sizeof(apellido));
                aux.setApellido(apellido);

                modifico = _regClientes.ModificarCliente(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "APELLIDO DE CLIENTE CAMBIADO CON EXITO" << endl;
                    system("pause");
                }
                else {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                return;
                break;
            case 3:
                system("cls");
                setConsoleSize(10, 60);
                cout << "INGRESE NUEVA CATEGORIA: " << endl;

                cin >> categoria;
                aux.setCategoria(categoria);

                modifico = _regClientes.ModificarCliente(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "CATEGORIA DE CLIENTE CAMBIADA CON EXITO" << endl;
                    system("pause");
                }
                else {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                return;
                break;
            case 4:
                system("cls");
                setConsoleSize(10, 60);
                cout << "INGRESE NUEVO EMAIL: " << endl;

                cin.ignore();
                cin.getline(email, sizeof(email));
                aux.setEmail(email);

                modifico = _regClientes.ModificarCliente(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "EMAIL DE CLIENTE CAMBIADO CON EXITO" << endl;
                    system("pause");
                }
                else {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                break;
            case 0:
                return;
                break;
            default:
                system("cls");
                setConsoleSize(10, 60);
                cout << "OPCION INVALIDA" << endl;
                system("pause");
                break;
            }
        }
    }
    else
    {
        system("cls");
        setConsoleSize(10, 60);
        cout << "NO SE ENCUENTRA CLIENTE EN SISTEMA" << endl;
        system("pause");
    }
}
void Manager::ListarClientes()
{
    Cliente cliente;
    system("cls");
    setConsoleSize(60, 170);
    cliente.mostrarEncabezado();
    _regClientes.ListarCliente(cliente);
    system("pause");
}
void Manager::BuscarCliente()
{
    system("cls");
    cout << "INGRESE EL DNI O EL ID DEL CLIENTE A BUSCAR:" << endl << endl;
    int num;
    cin >> num;
    Cliente cliente;
    cliente = _regClientes.BuscarCliente(num);
    if (cliente.getId() == -1)
    {
        cout << "NO SE ENCONTRO CLIENTE" << endl;
        system("pause");
        return;
    }
    system("cls");
    setConsoleSize(20, 170);
    cout << "CLIENTE ENCONTRADO: " << endl << endl;
    cliente.mostrarEncabezado();
    cliente.mostrarCliente();
    system("pause");
}

//METODOS PARA MANEJAR PROVEEDORES
void Manager::AltaProveedor(){
    system("cls");
    cout << "INGRESE LOS DATOS DEL NUEVO PROVEEDOR:" << endl << endl;
    Proveedor proveedor;
    int id = _regProveedores.ObtenerUltimoIdProveedor();
    proveedor.setId(id);
    proveedor.cargarProveedor();
    system("cls");
    cout << "Corrobore los datos:" << endl;
    setConsoleSize(20, 170);
    proveedor.mostrarEncabezadoSinID();
    proveedor.mostrarProveedorSinID();
    char opc;
    cout << endl << endl;
    cout << "DATOS CORRECTOS? (S/N)" << endl;
    cin >> opc;
    if (opc == 's' || opc == 'S')
    {
        bool alta;
        alta = _regProveedores.AltaProveedor(proveedor);
        system("cls");
        if (alta)  cout << "PROVEEDOR CARGADO CON EXITO" << endl;
        system("pause");
        return;
    }
    else {
        system("cls");
        cout << "DESEA CARGAR DE NUEVO EL PROVEEDOR? (S/N)" << endl;
        char opc2;
        cin >> opc2;
        if (opc2 == 's' || opc2 == 'S')
        {
            AltaCliente();
            return;
        }
        else
        {
            return;
        }
    }
}
void Manager::BajaProveedor(){
    system("cls");
    Proveedor aux;
    bool borro = false;
    int ID_DNI;
    setConsoleSize(10, 60);
    cout << "Ingrese el ID o CUIL del proveedor a borrar: ";
    cin >> ID_DNI;
    cout << endl;

    aux = _regProveedores.BuscarProveedor(ID_DNI);

    if (aux.getId() != -1)
    {
        setConsoleSize(20, 170);
        int opc;
        cout << endl;
        aux.mostrarEncabezado();
        aux.mostrarProveedor();
        cout << endl;
        cout << "Se encontro proveedor!" << "Desea borrar?" << endl;
        cout << "1- SI" << endl;
        cout << "2- NO" << endl;
        cout << "Opcion elegida: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            system("cls");
            borro = _regProveedores.BajaProveedor(aux.getId());

            if (borro)
            {
                system("cls");
                setConsoleSize(10, 60);
                cout << "Proveedor borrado" << endl;
                system("pause");
            }
            break;
        case 2:
            return;
            break;
        default:
            system("cls");
            setConsoleSize(10, 60);
            cout << "OPCION INVALIDA" << endl;
            system("pause");
            return;
            break;
        }
    }
    else
    {
        system("cls");
        setConsoleSize(10, 60);
        cout << "NO SE ENCUENTRA PROVEEDOR EN SISTEMA" << endl;
        system("pause");
        return;
    }
}
void Manager::ModificarProveedor(){
    system("cls");
    Proveedor aux;
    bool modifico = false;
    char nombre[40], tipo[50], email[50];
    int id;

    setConsoleSize(10, 60);
    cout << "Ingrese el ID o DNI del proveedor a modificar: ";
    cin >> id;
    cout << endl;

    aux = _regProveedores.BuscarProveedor(id);

    if (aux.getId() != -1)
    {

        while (true)
        {
            system("cls");
            setConsoleSize(25, 170);
            aux.mostrarEncabezado();
            aux.mostrarProveedor();
            cout << endl << endl;
            int opc, pos;
            pos = _regProveedores.BuscarPosicion(aux);
            cout << "Se encontro Proveedor!" << "Que desea cambiar?" << endl;
            cout << "1- Nombre razon social" << endl;
            cout << "2- Tipo" << endl;
            cout << "3- Email" << endl;
            cout << "0- Cancelar" << endl;
            cout << "Opcion elegida: ";
            cin >> opc;
            switch (opc)
            {
            case 1:
                system("cls");
                setConsoleSize(15, 60);
                cout << "INGRESE NUEVO NOMBRE RAZON SOCIAL: " << endl;

                cin.ignore();
                cin.getline(nombre, sizeof(nombre));
                aux.setNombre(nombre);

                modifico = _regProveedores.ModificarProveedor(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "RAZON SOCIAL DE PROVEEDOR CAMBIADA CON EXITO" << endl;
                    system("pause");
                }
                else {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                return;
                break;
            case 2:
                system("cls");
                setConsoleSize(15, 60);
                cout << "INGRESE NUEVO TIPO: " << endl;

                cin.ignore();
                cin.getline(tipo, sizeof(tipo));
                aux.setTipo(tipo);

                modifico = _regProveedores.ModificarProveedor(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "TIPO DE PROVEEDOR CAMBIADO CON EXITO" << endl;
                    system("pause");
                }
                else {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                return;
                break;
            case 3:
                system("cls");
                setConsoleSize(15, 60);
                cout << "INGRESE NUEVO EMAIL: " << endl;

                cin.ignore();
                cin.getline(email, sizeof(email));
                aux.setEmail(email);

                modifico = _regProveedores.ModificarProveedor(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "EMAIL DE PROVEEDOR CAMBIADO CON EXITO" << endl;
                    system("pause");
                }
                else {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                break;
            case 0:
                return;
                break;
            default:
                system("cls");
                setConsoleSize(15, 60);
                cout << "OPCION INVALIDA" << endl;
                system("pause");
                break;
            }
        }
    }
    else
    {
        system("cls");
        setConsoleSize(10, 60);
        cout << "NO SE ENCUENTRA CLIENTE EN SISTEMA" << endl;
        system("pause");
    }
}
void Manager::ListarProveedor(){
    Proveedor proveedor;
    system("cls");
    setConsoleSize(60, 170);
    proveedor.mostrarEncabezado();
    _regProveedores.ListarProveedor(proveedor);
    system("pause");
}
void Manager::BuscarProveedor(){
    system("cls");
    cout << "INGRESE EL CUIL O EL ID DEL PROVEEDOR A BUSCAR:" << endl << endl;
    int num;
    cin >> num;
    Proveedor proveedor;
    proveedor = _regProveedores.BuscarProveedor(num);
    if (proveedor.getId() == -1)
    {
        cout << "NO SE ENCONTRO PROVEEDOR" << endl;
        system("pause");
        return;
    }
    system("cls");
    setConsoleSize(20, 170);
    cout << "PROVEEDOR ENCONTRADO: " << endl << endl;
    proveedor.mostrarEncabezado();
    proveedor.mostrarProveedor();
    system("pause");
}

void Manager::CargarVenta()
{
    system("cls");
    Factura Nuevafactura;
    Producto producto;
    Cliente cliente;
    std::vector<DetalleFactura> NuevoDetalle; // se crea el vector dinamico

    int dni;
    float montoTotal = 0;

    cout << "INGRESE DNI DE CLIENTE: ";
    cin >> dni;

    cliente = _regClientes.BuscarCliente(dni);
    if (cliente.getId() == -1)
    {
        cout << "NO EXISTE CLIENTE EN BASE DE DATOS. CARGUE NUEVO CLIENTE" << endl;
        system("pause");
        AltaCliente();
    }
    else { 
        cout << "CLIENTE EN BASE DE DATOS" << endl;
        system("pause");
        system("cls");

        Nuevafactura.setId(_regFacturas.ObtenerUltimoIdFactura() + 1);
        bool continuar = true;

       // COMPRA EN LOOP
        while (continuar)
        {
            system("cls");
            cout << "INGRESE ID DE ARTICULO: ";
            int id;
            cin >> id;
            producto = _regProductos.BuscarProducto(id);
            if (producto.GetId() == -1)
            {
                system("cls");
                cout << "EL PRODUCTO NO EXISTE. DESEA CONTINUAR CON LA COMPRA? (1-SI / 0 -NO)" << endl;
                cin >> continuar;
            }
            else {
                cout << "INGRESE CANTIDAD A COMPRAR: ";
                int cantidad;
                cin >> cantidad;
                if (_regProductos.verificarStock(producto, cantidad)==false)
                {
                    cout << "no hay suficiente stock de producto para la compra" << endl;
                    cout << "¿Desea agregar otro producto? (1 - Sí, 0 - No): ";
                    cin >> continuar;
                }
                else {
                    float precioUnitario = producto.GetPrecioVenta();
                    float monto = precioUnitario * cantidad;

                    DetalleFactura detalle;
                    detalle.cargarFactura(Nuevafactura.getId(),producto, cantidad);

                    NuevoDetalle.push_back(detalle);
                    montoTotal += monto;
                
                    // MOSTRAR DETALLE
                    system("cls");
                    setConsoleSize(35, 95);

                    cout << "******DETALLES ACTUALES*******" << endl << endl;
                    
                    for (int i = 0; i < NuevoDetalle.size(); ++i) {
                        if (i == 0)
                        {
                            NuevoDetalle[i].mostrarEncabezado();
                        }
                        //cout << "Detalle " << i + 1 << ": ";
                        NuevoDetalle[i].mostrarDetalle();
                    }
                    cout << "Desea agregar otro producto? (1 - SI, 0 - No): ";
                    cin >> continuar;
                }
            }
    }
        // revisar detalle
        bool revisarDetalle = true;

        if (NuevoDetalle[0].getIdFactura()==-1)
        {
            bool revisarDetalle = false;
        }

        while (revisarDetalle) {
            int opcion;
            cout << "Desea revisar o eliminar algun detalle? (1 - SI / 0 - NO): ";
            cin >> opcion;

            if (opcion == 1) {
                int detalleIndex;
                cout << "Ingrese el numero del detalle a eliminar (1 a " << NuevoDetalle.size() << "): ";    
                cin >> detalleIndex;

                if (detalleIndex >= 1 && detalleIndex <= NuevoDetalle.size()) {
                    montoTotal -= NuevoDetalle[detalleIndex - 1].getMontoTotal();
                    NuevoDetalle.erase(NuevoDetalle.begin() + detalleIndex - 1);

                    cout << "Detalle eliminado. Monto total actualizado: " << montoTotal << endl;
                    // Mostrar detalles actualizados
                    cout << "Detalles actuales:" << endl;
                    for (int i = 0; i < NuevoDetalle.size(); ++i) {
                        if (i == 0)
                        {
                            NuevoDetalle[i].mostrarEncabezado();
                        }
                        //cout << "Detalle " << i + 1 << ": ";
                        NuevoDetalle[i].mostrarDetalle();
                    }
                }
                else {
                    cout << "Número de detalle inválido." << endl;
                }
            }
            else if (opcion == 0) {
                revisarDetalle = false;
            }
            else {
                cout << "Opción inválida." << endl;
            }
        }
}
    // confirmar y guardar
    Nuevafactura.Cargar(cliente.getId(), montoTotal);
    _regFacturas.AltaFactura(Nuevafactura);

    for (int i = 0; i < NuevoDetalle.size(); i++)
    {
        if (NuevoDetalle[i].getEstado()==true)
        {
        _regDetalle.altaDetalle(NuevoDetalle[i]);
        _regProductos.ajustarStock(NuevoDetalle[i].getProducto(), NuevoDetalle[i].getCantidad());
        }
    }
    cout << "VENTA REALIZADA" << endl;
    system("pause");
}

void Manager::listarVentas()
{
    system("cls");
    setConsoleSize(50, 115);
    _factura.MostrarEncabezado();
    _regFacturas.ListarFactura(_factura);
    system("pause");
}

void Manager::reporteCaja()
{
    int dia, mes, anio;

    cout << "INGRESE DIA - MES - ANIO (XXYYZZZZ) " << endl;
    cout << "DIA: ";
    cin >> dia;
    cout << endl;
    cout << "MES: ";
    cin >> mes;
    cout << endl;
    cout << "ANIO: ";
    cin >> anio;

    Factura aux;
    aux.setFecha(dia, mes, anio);
    float monto = _regFacturas.listarReporteCaja(aux.getFecha());

    system("cls");
    setConsoleSize(15, 50);
    cout << "EN EL DIA DE LA FECHA: " << aux.getFecha().toString() << " FACTURO: " << endl;
    cout << "$ " << monto << endl << endl;
    system("pause");
}

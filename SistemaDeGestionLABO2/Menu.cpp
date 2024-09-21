#include "Menu.h"

void Menu::MostrarEntrada()
{
    while (true)
    {
        system("cls");
        int opcion;
        cout << left;
        cout << "***********************" << endl;
        cout << "** " << _fechaSitema.toString() << " - " << _fechaSitema.getNombreDia() << " **" << endl;
        cout << "***********************" << endl
            << endl;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "-----------------BIENVENIDO-----------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú inicial
        cout << setw(40) << "1. ENTRAR AL SISTEMA" << endl;
        cout << setw(40) << "2. CREDITOS" << endl;
        cout << setw(40) << "0. SALIR" << endl;
        setConsoleSize(45, 45);

        cin >> opcion;

        switch (opcion)
        {
        case 1:

            if (_manager.entradaAlSistema())
            {
                mostrar();
            }
            //mostrar();
            break;
        case 2:
            system("cls");
            setConsoleSize(25, 45);
            cout << endl;
            cout << "GRUPO 3 - LABORATORIO DE PROGRAMACION II " << endl;
            cout << endl;
            cout << "**************INTEGRANTES*************** " << endl;
            cout << endl;
            cout << "Javier Alejandro Ordóñez. Legajo: 26040 " << endl;
            cout << "María Itatí Romero. Legajo:  29888 " << endl;
            cout << "Sasha Emanuel Franco. Legajo: 27984 " << endl;
            cout << endl;
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            "OPCION INCORRECTA, ELIJA DE NUEVO";
            system("pause");
            break;
        }
    }
}
void Menu::mostrar()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << "***********************" << endl;
        cout << "** " << _fechaSitema.toString() << " - " << _fechaSitema.getNombreDia() << " **" << endl;
        cout << "***********************" << endl
            << endl;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "--------BIENVENIDO AL MENU PRINCIPAL--------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú principal
        cout << setw(40) << "1. GESTIONAR COMPRAS - STOCK" << endl;
        cout << setw(40) << "2. REALIZAR VENTA" << endl;
        cout << setw(40) << "3. ABM" << endl;
        cout << setw(40) << "4. EMITIR REPORTES - EXPORTAR DATOS" << endl;
        cout << setw(40) << "5. GESTION DE USUARIOS" << endl; // terminado
        cout << setw(40) << "6. BACKUP DE ARCHIVOS" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            mostrarCompras();
            break;
        case 2:
            mostrarVentas();
            break;
        case 3:
            mostrarABM();
            break;
        case 4:
            mostrarRreportes();
            break;
        case 5:
            if (_manager.permisosAdmin())
            {
                mostrarUsuarios();

            }
            else
            {
                system("cls");
                cout << "NO TIENE PERMISOS DE ADMINISTRADOR" << endl;
                system("pause");
            }
            break;
        case 6:
            mostrarBk();
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}
void Menu::mostrarCompras()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "---------------MENU DE COMPRAS--------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de compras
        cout << setw(40) << "1. LISTAR STOCK DE PRODUCTOS" << endl;
        cout << setw(40) << "2. BUSCAR STOCK DE PRODUCTO POR ID" << endl;
        cout << setw(40) << "3. INGRESAR COMPRA" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            _manager.ListarStock();
            system("pause");
            break;
        case 2:
            _manager.BuscarStock();
            break;
        case 3:
            _manager.CargarCompra(); // corregir, ya que borra cosas
            system("pause");
            break;
        case 4:
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
} //USAR FACTURA Y DETALLE
void Menu::mostrarVentas()
{
    //while (true)
    //{
    //    system("cls");
    //    int opc;
    //    cout << left;
    //    cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
    //    cout << setw(40) << "--------------------------------------------" << endl;
    //    cout << setw(40) << "---------------MENU DE VENTAS---------------" << endl;
    //    cout << setw(40) << "--------------------------------------------" << endl;
    //    // Opciones del menú de ventas
    //    cout << setw(40) << "1. INGRESAR VENTA DE UN ARTICULO" << endl;
    //    cout << setw(40) << "2. INGRESAR VENTA DE VARIOS ARTICULOS" << endl;
    //    cout << setw(40) << "--------------------------------------------" << endl;
    //    cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
    //    setConsoleSize(45, 45);
    //    cin >> opc;

    //    switch (opc)
    //    {
    //    case 1:
    //        break;
    //    case 2:
    //        break;
    //    case 0:
    //        return;
    //        break;
    //    default:
    //        cout << "INGRESE UNA OPCION VALIDA" << endl;
    //        system("pause");
    //        break;
    //    }
    //}

    _manager.CargarVenta();
}
void Menu::mostrarABM()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "----------------MENU PARA ABM---------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de ABM
        cout << setw(40) << "1. ABM DE CLIENTES" << endl;
        cout << setw(40) << "2. ABM DE PROVEEDORES" << endl;
        cout << setw(40) << "3. ABM DE PRODUCTOS" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            mostrarABMCLientes();
            break;
        case 2:
            mostrarABMProveedores();
            break;
        case 3:
            mostrarABMProductos();
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}
void Menu::mostrarRreportes()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "----------------MENU REPORTES---------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de reportes
        cout << setw(40) << "1. LISTADO DE VENTAS" << endl;
        cout << setw(40) << "2. EMITIR REPORTE DE CAJA" << endl;
        cout << setw(40) << "3. EXPORTAR REPORTES A CSV" << endl; // lLISTO
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            _manager.listarVentas();
            break;
        case 2:
            _manager.reporteCaja();
            break;
        case 3:
            exportarClientesACSV();
            exportarProductosACSV();
            exportarProveedoresACSV();
            exportarUsuariosACSV();
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
} // TERMINAR
void Menu::mostrarUsuarios()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "----------------MENU USUARIOS---------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de usuarios del sistema
        cout << setw(40) << "1. LISTAR USUARIOS" << endl;
        cout << setw(40) << "2. CREAR NUEVO USUARIO" << endl;
        cout << setw(40) << "3. MODIFICAR USUARIO" << endl;
        cout << setw(40) << "4. ELIMINAR USUARIO" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            _manager.listarUsuarios();
            break;
        case 2:
            _manager.AltaUsuarios();
            break;
        case 3:
            _manager.MoidificarUsuarios();
            break;
        case 4:
            _manager.BajaUsuario();
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}

//************************************************************************************************************************
// MENU DE BACKUPS
void Menu::mostrarBk()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE HALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "-----------------MENU BACKUP----------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú para BK
        cout << setw(40) << "1. HACER BACKUP CLIENTES" << endl;
        cout << setw(40) << "2. HACER BACKUP PROVEEDORES" << endl;
        cout << setw(40) << "3. HACER BACKUP PRODUCTOS" << endl;
        // cout << setw(40) << "4. MOSTRAR BACKUP CLIENTES" << endl;
        // cout << setw(40) << "5. MOSTRAR BACKUP PROVEEDORES" << endl;
        // cout << setw(40) << "6. MOSTRAR BACKUP PRODUCTOS" << endl;
        cout << setw(40) << "7. RESTAURAR BACKUP" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            _backup.backupClientes();
            break;
        case 2:
            _backup.backupProveedores();
            break;
        case 3:
            _backup.backupProductos();
            break;
            /*case 4:
                mostrarClientesBackup();
                break;
            case 5:
                mostrarProveedoresBackup();
                break;
            case 6:
                mostrarProductosBackup();
                break;*/
        case 7:
            mostrarRestauracionBK();
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}
// FIN MENU DE BACKUPS**********************************************************************

//*****************************************************************************************
// MENU RESTAURACION DE BACKUPS
//*****************************************************************************************
void Menu::mostrarRestauracionBK()
{
    while (true)
    {

        // const string archivoCSV;
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "--------MENU RESTAURACIÓN DE BACKUPS--------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de restauraciones
        cout << setw(40) << "1. RESTAURAR BACKUP CLIENTES" << endl;
        cout << setw(40) << "2. RESTAURAR BACKUP PROVEEDORES" << endl;
        cout << setw(40) << "3. RESTAURAR BACKUP PRODUCTOS" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            restaurarBackup("ClientesBackup.dat", "Clientes.dat");
            break;
        case 2:
            restaurarBackup("ProveedoresBackup.dat", "Proveedores.dat");
            break;
        case 3:
            restaurarBackup("ProductosBackup.dat", "Productos.dat");
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}
// FIN MENU DE RESTAURACION DE BACKUP*******************************************************

//*****************************************************************************************
// EXPORTAR DATOS
//
void Menu::mostrarExportaciones()
{
    while (true)
    {
        const string archivoCSV;
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "----------------MENU EXPORTAR ARCHIVOS------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de exportaciones
        cout << setw(40) << "1. EXPORTAR CLIENTES" << endl;
        cout << setw(40) << "2. EXPORTAR PROVEEDORES" << endl;
        cout << setw(40) << "3. EXPORTAR PRODUCTOS" << endl;
        cout << setw(40) << "4. EXPORTAR USUARIOS" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            // exportarClientesACSV();
            break;
        case 2:
            // exportarProveedoresACSV();
            break;
        case 3:
            // exportarProductosACSV();
            break;
        case 4:
            // exportarUsuariosACSV();
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}
// FIN EXPORTAR DATOS************************************************************************

void Menu::mostrarABMCLientes()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "--------------MENU ABM CLIENTES-------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de ABM
        cout << setw(40) << "1. ALTA DE CLIENTE NUEVO" << endl;
        cout << setw(40) << "2. BAJA DE CLIENTE" << endl;
        cout << setw(40) << "3. MODIFICAR CLIENTE" << endl;
        cout << setw(40) << "4. LISTAR CLIENTES" << endl;
        cout << setw(40) << "5. BUSCAR CLIENTE POR ID O DNI" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            _manager.AltaCliente();
            break;
        case 2:
            if (_manager.permisosAdmin())
            {
                _manager.BajaCliente();
            }
            else {
                system("cls");
                cout << "NO TIENE PERMISOS DE ADMINISTRADOR" << endl;
                system("pause");
            }
            break;
        case 3:
            if (_manager.permisosAdmin())
            {
                _manager.ModificarCliente();
            }
            else {
                system("cls");
                cout << "NO TIENE PERMISOS DE ADMINISTRADOR" << endl;
                system("pause");
            }
            break;
        case 4:
            _manager.ListarClientes();
            break;
        case 5:
            _manager.BuscarCliente();
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}
void Menu::mostrarABMProveedores()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "------------MENU ABM PROVEEDORES------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de ABM
        cout << setw(40) << "1. ALTA DE PROVEEDOR NUEVO" << endl;
        cout << setw(40) << "2. BAJA DE PROVEEDOR" << endl;
        cout << setw(40) << "3. MODIFICAR PROVEEDOR" << endl;
        cout << setw(40) << "4. LISTAR PROVEEDOR" << endl;
        cout << setw(40) << "5. BUSCAR PROVEEDOR POR ID O DNI" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            _manager.AltaProveedor();
            break;
        case 2:
            if (_manager.permisosAdmin())
        {
            _manager.BajaProveedor();
        }
              else {
            system("cls");
            cout << "NO TIENE PERMISOS DE ADMINISTRADOR" << endl;
            system("pause");
        }
            break;
        case 3:
            if (_manager.permisosAdmin())
            {
                _manager.ModificarProveedor();
            }
            else {
                system("cls");
                cout << "NO TIENE PERMISOS DE ADMINISTRADOR" << endl;
                system("pause");
            }
            break;
        case 4:
            _manager.ListarProveedor();
            break;
        case 5:
            _manager.BuscarProveedor();
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}
void Menu::mostrarABMProductos()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "------------MENU ABM PRODUCTOS--------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de ABM
        cout << setw(40) << "1. ALTA DE PRODUCTO NUEVO" << endl;
        cout << setw(40) << "2. BAJA DE PRODUCTO" << endl;
        cout << setw(40) << "3. MODIFICAR PRODUCTO" << endl;
        cout << setw(40) << "4. LISTAR PRODUCTOS" << endl;
        cout << setw(40) << "5. BUSCAR PRODUCTO POR ID" << endl;
        cout << setw(40) << "6. BUSCAR PRODUCTO POR NOMBRE" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            _manager.AltaProducto();
            break;
        case 2:
            if (_manager.permisosAdmin())
            {
                _manager.BajaProducto(); // ya funciona
            }
            else {
                system("cls");
                cout << "NO TIENE PERMISOS DE ADMINISTRADOR" << endl;
                system("pause");
            }
            break;
        case 3:
            if (_manager.permisosAdmin())
            {
                _manager.MoidificarProducto();
            }
            else {
                system("cls");
                cout << "NO TIENE PERMISOS DE ADMINISTRADOR" << endl;
                system("pause");
            }
            break;
        case 4:
            _manager.listarProducto();
            break;
        case 5:
            _manager.BuscarProductoXID();
            break;
        case 6:
            _manager.BuscarProductoXNombre();
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}

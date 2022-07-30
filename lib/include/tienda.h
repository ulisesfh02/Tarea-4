#ifndef MI_TIENDA
#define MI_TIENDA

#include "Producto.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Tienda{

    char nombreTienda[15];
    char emailTienda[24];
    char direccionTienda[24];
    char telefono[8];
    vector<Producto *> inventarioTienda;

    public:
    Tienda();
    Tienda(string, string, string, string);
    ~Tienda();
    string obtenerInfoTienda();
    void cambiarInfoTienda(string, string, string, string);

    string obtenerNombreTienda();
    string obtenerEmailTienda();
    string obtenerDireccionTienda();
    string obtenerTelefonoTienda();

    void insertarProducto(Producto*);
    void eliminarProducto(int);
    void modificarProducto(int, string, int);
    Producto *identificarProducto(int);
    string consultarProductos();
    int obtenerCantidadDeProductos();
    vector<Producto *> obtenerProductos();

    void guardarEnArchivoBinario(ostream*);
    void cargarDesdeArchivoBinario(istream*);

    friend ostream& operator << (ostream &o, const Tienda*);
};

#endif

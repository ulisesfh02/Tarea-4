#ifndef MI_PRODUCTO
#define MI_PRODUCTO

#include <string>
using namespace std;

class Producto{

    int idProducto;
    char nombreProducto[20];
    int existencias;

    public:
    Producto();
    Producto(int, string, int);
    string obtenerInfoProducto();
    int obtenerIdProducto();
    string obtenerNombreProducto();
    int obtenerExistenciasProducto();
    void modificarValores(int, string, int);

    friend ostream& operator << (ostream &o, const Producto*);
};

#endif

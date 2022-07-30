#ifndef EXCEPCION_TIENDA_SIN_PRODUCTOS
#define EXCEPCION_TIENDA_SIN_PRODUCTOS

#include <exception>
using namespace std;

class ExcepcionTiendaSinProductos : public exception{

    public:
    ExcepcionTiendaSinProductos() noexcept = default;
    ~ExcepcionTiendaSinProductos() = default;

    virtual const char* what() const noexcept{
        return "La tienda actualmente no tiene productos";
    }
};

#endif
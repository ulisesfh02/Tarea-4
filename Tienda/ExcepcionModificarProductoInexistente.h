#ifndef EXCEPCION_MODIFICAR_PRODUCTO_INEXISTENTE
#define EXCEPCION_MODIFICAR_PRODUCTO_INEXISTENTE

#include <exception>
using namespace std;

class ExcepcionModificarProductoInexistente : public exception{

    public:
    ExcepcionModificarProductoInexistente() noexcept = default;
    ~ExcepcionModificarProductoInexistente() = default;

    virtual const char* what() const noexcept{
        return "El producto a modificar no existe";
    }
};

#endif
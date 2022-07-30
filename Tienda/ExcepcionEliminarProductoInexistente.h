#ifndef EXCEPCION_ELIMINAR_PRODUCTO_INEXISTENTE
#define EXCEPCION_ELIMINAR_PRODUCTO_INEXISTENTE

#include <exception>
using namespace std;

class ExcepcionEliminarProductoInexistente : public exception{

    public:
    ExcepcionEliminarProductoInexistente() noexcept = default;
    ~ExcepcionEliminarProductoInexistente() = default;

    virtual const char* what() const noexcept{
        return "El producto a eliminar no existe";
    }
};

#endif
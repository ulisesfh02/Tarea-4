#ifndef EXCEPCION_INSERTAR_PRODUCTO_INEXISTENTE
#define EXCEPCION_INSERTAR_PRODUCTO_INEXISTENTE

#include <exception>
using namespace std;

class ExcepcionInsertarProductoExistente : public exception{

    public:
    ExcepcionInsertarProductoExistente() noexcept = default;
    ~ExcepcionInsertarProductoExistente() = default;

    virtual const char* what() const noexcept{
        return "El producto a insertar ya existe";
    }
};

#endif
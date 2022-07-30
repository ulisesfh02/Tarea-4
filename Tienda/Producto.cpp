#include "Producto.h"
#include <cstring>
#include <sstream>
using namespace std;

Producto::Producto(){
    this->idProducto= 0;
    strcpy(this->nombreProducto, "");
    this->existencias= 0;
}

Producto::Producto(int idProducto, string nombreProducto, int existencias){
    this->idProducto= idProducto;
    strcpy(this->nombreProducto, nombreProducto.c_str());
    this->existencias= existencias;
}

int Producto::obtenerIdProducto(){
    return this->idProducto;
}

string Producto::obtenerNombreProducto(){
    return this->nombreProducto;
}

int Producto::obtenerExistenciasProducto(){
    return this->existencias;
}


string Producto::obtenerInfoProducto(){
    string out="";
    stringstream outStream;
    outStream << this->idProducto << " " << this->nombreProducto << " " << this->existencias;
    out= outStream.str();
    return out;
}

void Producto::modificarValores(int idProducto, string nombreProducto, int existencias){
    this->idProducto= idProducto;
    strcpy(this->nombreProducto, nombreProducto.c_str());
    this->existencias= existencias;
}

ostream& operator << (ostream &o, const Producto *producto) {

    o << producto->idProducto << " " << producto->nombreProducto << " " << producto->existencias;

    return o;
}

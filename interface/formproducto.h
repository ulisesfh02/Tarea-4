#ifndef FORMPRODUCTO_H
#define FORMPRODUCTO_H

#include <QDialog>

namespace Ui {
class formProducto;
}

class formProducto : public QDialog
{
    Q_OBJECT

public:
    explicit formProducto(QWidget *parent = nullptr);
    ~formProducto();

    void cargarInformacion(int, std::string, int);
    int obtenerId();
    std::string obtenerNombre();
    int obtenerExistencias();

private:
    Ui::formProducto *ui;
};

#endif // FORMPRODUCTO_H

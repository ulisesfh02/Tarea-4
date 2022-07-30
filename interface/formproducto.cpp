#include "formproducto.h"
#include "ui_formproducto.h"

formProducto::formProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formProducto)
{
    ui->setupUi(this);
}

formProducto::~formProducto()
{
    delete ui;
}

void formProducto::cargarInformacion(int id, std::string nombre, int existencias){
    QString idString = QString::number(id);
    this->ui->idProducto->setText(idString);
    this->ui->idProducto->setReadOnly(true);

    QString nombreString = QString::fromStdString(nombre);
    this->ui->nombreProducto->setText(nombreString);

    QString existenciasString = QString::number(existencias);
    this->ui->existenciasProducto->setText(existenciasString);
}

int formProducto::obtenerId(){
    int id = (this->ui->idProducto->text()).toInt();
    return id;
}

std::string formProducto::obtenerNombre(){
    std::string nombre = (this->ui->nombreProducto->text()).toStdString();
    return nombre;
}

int formProducto::obtenerExistencias(){
    int existencias = (this->ui->existenciasProducto->text()).toInt();
    return existencias;
}

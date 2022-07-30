#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_formproducto.h"
#include "formproducto.h"
#include <QMessageBox>
#include <sstream>
#include <QFileDialog>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tienda = new Tienda("Super Ulises", "superulises@u.com", "Casa de Ulises", "34567345");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tienda;
}


void MainWindow::on_showInfo_clicked()
{
    string stringNombreTienda = this->tienda->obtenerNombreTienda();
    QString nombreTienda = QString::fromStdString(stringNombreTienda);
    this->ui->nombreTienda->setText(nombreTienda);

    string stringEmailTienda = this->tienda->obtenerEmailTienda();
    QString emailTienda = QString::fromStdString(stringEmailTienda);
    this->ui->emailTienda->setText(emailTienda);

    string stringDireccionTienda = this->tienda->obtenerDireccionTienda();
    QString direccionTienda = QString::fromStdString(stringDireccionTienda);
    this->ui->direccionTienda->setText(direccionTienda);

    string stringTelefonoTienda = this->tienda->obtenerTelefonoTienda();
    QString telefonoTienda = QString::fromStdString(stringTelefonoTienda);
    this->ui->telefonoTienda->setText(telefonoTienda);
}


void MainWindow::on_btnAgregarProducto_clicked()
{
    formProducto formProducto (this);
    int result = formProducto.exec();

    if(result == QDialog::Accepted){
        //Se llama a la biblioteca
        int idProducto = formProducto.obtenerId();
        std::string nombreProducto = formProducto.obtenerNombre();
        int existenciasProducto = formProducto.obtenerExistencias();

        Producto * productoNuevo = new Producto(idProducto, nombreProducto, existenciasProducto);
        tienda->insertarProducto(productoNuevo);

        QString stringNombre = QString::fromStdString(nombreProducto);

        QString producto = QString::fromStdString(productoNuevo->obtenerInfoProducto());
        QListWidgetItem *itemNuevo = new QListWidgetItem(producto);
        itemNuevo->setData(1, idProducto);
        itemNuevo->setData(2, stringNombre);
        itemNuevo->setData(3, existenciasProducto);

        this->ui->listaProductos->addItem(itemNuevo);

        QMessageBox * msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Aceptado");
        msgBox->setText("Producto agregado");
        msgBox->open();
    }
    else{
        QMessageBox * msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Cancelado");
        msgBox->setText("Proceso cancelado");
        msgBox->open();
    }
}


void MainWindow::on_btnModificarProducto_clicked()
{
    QListWidgetItem * productoSeleccionado = this->ui->listaProductos->currentItem();

    if(productoSeleccionado == nullptr){
        QMessageBox * msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Error");
        msgBox->setText("No hay item seleccionado");
        msgBox->open();
    }
    else{
        QString stringId = productoSeleccionado->data(1).toString();
        QString stringNombre = productoSeleccionado->data(2).toString();
        QString stringExistencias = productoSeleccionado->data(3).toString();

        int idProducto = stringId.toInt();
        std::string nombreProducto = stringNombre.toStdString();
        int existenciasProducto = stringExistencias.toInt();


        formProducto formProducto {this};
        formProducto.cargarInformacion(idProducto, nombreProducto, existenciasProducto);

        int result = formProducto.exec();
        if(result == QDialog::Accepted){
            int idProducto = formProducto.obtenerId();
            std::string nombreProducto = formProducto.obtenerNombre();
            int existenciasProducto = formProducto.obtenerExistencias();

            tienda->modificarProducto(idProducto, nombreProducto, existenciasProducto);
            Producto * productoABuscar = tienda->identificarProducto(idProducto);

            QString productoModificado = QString::fromStdString(productoABuscar->obtenerInfoProducto());
            productoSeleccionado->setText(productoModificado);

            QString stringNombre = QString::fromStdString(nombreProducto);

            productoSeleccionado->setData(1, idProducto);
            productoSeleccionado->setData(2, stringNombre);
            productoSeleccionado->setData(3, existenciasProducto);

            QMessageBox * msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Modificado");
            msgBox->setText("Producto modificado exitosamente!");
            msgBox->open();
        }
        else{
            QMessageBox * msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Cancelado");
            msgBox->setText("Proceso cancelado");
            msgBox->open();
        }
    }
}


void MainWindow::on_btnEliminarProducto_clicked()
{
    QListWidgetItem * productoSeleccionado = this->ui->listaProductos->currentItem();

    if(productoSeleccionado == nullptr){
        QMessageBox * msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Error");
        msgBox->setText("No hay item seleccionado");
        msgBox->open();
    }
    else{
        QString stringId = productoSeleccionado->data(1).toString();

        int idProducto = stringId.toInt();

        tienda->eliminarProducto(idProducto);

        delete productoSeleccionado;

        QMessageBox * msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Eliminado");
        msgBox->setText("El producto ha sido eliminado");
        msgBox->open();
    }
}


void MainWindow::on_cargarArchivoBinario_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                "Abrir archivo de datos", "",
                tr("Archivo de datos (*.dat);;All Files (*)"));


    if (fileName != "")
    {
        // Convertir QString a std::string
        std::string name = fileName.toStdString();

        ifstream archivoEntrada;
        archivoEntrada.open(name, ios::in|ios::binary);

        if (!archivoEntrada.is_open())
        {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error al cargar");
            msgbox->setText("Error cargando el archivo");
            msgbox->open();
            return;
        }

        tienda->cargarDesdeArchivoBinario(&archivoEntrada);

        string stringNombreTienda = this->tienda->obtenerNombreTienda();
        QString nombreTienda = QString::fromStdString(stringNombreTienda);
        this->ui->nombreTienda->setText(nombreTienda);

        string stringEmailTienda = this->tienda->obtenerEmailTienda();
        QString emailTienda = QString::fromStdString(stringEmailTienda);
        this->ui->emailTienda->setText(emailTienda);

        string stringDireccionTienda = this->tienda->obtenerDireccionTienda();
        QString direccionTienda = QString::fromStdString(stringDireccionTienda);
        this->ui->direccionTienda->setText(direccionTienda);

        string stringTelefonoTienda = this->tienda->obtenerTelefonoTienda();
        QString telefonoTienda = QString::fromStdString(stringTelefonoTienda);
        this->ui->telefonoTienda->setText(telefonoTienda);

        int tamanioInventario= tienda->obtenerCantidadDeProductos();
        vector<Producto *> productos = tienda->obtenerProductos();
        for(int i=0; i < tamanioInventario; i++){
            QString producto = QString::fromStdString(productos[i]->obtenerInfoProducto());
            QListWidgetItem *itemNuevo = new QListWidgetItem(producto);

            QString stringNombre = QString::fromStdString(productos[i]->obtenerNombreProducto());

            itemNuevo->setData(1, productos[i]->obtenerIdProducto());
            itemNuevo->setData(2, stringNombre);
            itemNuevo->setData(3, productos[i]->obtenerExistenciasProducto());

            this->ui->listaProductos->addItem(itemNuevo);
        }
    }

}



void MainWindow::on_guardarArchivoBinario_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
            "Guardar archivo de datos", "",
            tr("Archivo de datos (*.dat);;All Files (*)"));


    if (fileName != "")
    {
        // Convertir QString a std::string
        std::string name = fileName.toStdString();

        ofstream ofs(name, std::ifstream::out); // Por default abriendo como texto

        if (!ofs.is_open())
        {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Error al guardar");
            msgbox->setText("Error escribiendo el archivo");
            msgbox->open();
            return;
        }

        QString nombreTienda = this->ui->nombreTienda->text();
        std::string stringNombreTienda = nombreTienda.toStdString();

        QString emailTienda = this->ui->emailTienda->text();
        std::string stringEmailTienda = emailTienda.toStdString();

        QString direccionTienda = this->ui->direccionTienda->text();
        std::string stringDireccionTienda = direccionTienda.toStdString();

        QString telefonoTienda = this->ui->telefonoTienda->text();
        std::string stringTelefonoTienda = telefonoTienda.toStdString();

        tienda->cambiarInfoTienda(stringNombreTienda, stringEmailTienda, stringDireccionTienda, stringTelefonoTienda);

        tienda->guardarEnArchivoBinario(&ofs);
        ofs.close();
    }
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <../Tienda/tienda.h>
#include <../Tienda/Producto.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_showInfo_clicked();

    void on_btnAgregarProducto_clicked();

    void on_btnModificarProducto_clicked();

    void on_btnEliminarProducto_clicked();

    void on_cargarArchivoBinario_clicked();

    void on_guardarArchivoBinario_clicked();

private:
    Ui::MainWindow *ui;
    Tienda * tienda;
};
#endif // MAINWINDOW_H

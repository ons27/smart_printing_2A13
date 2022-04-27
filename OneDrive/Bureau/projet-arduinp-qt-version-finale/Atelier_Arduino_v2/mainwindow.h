#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "arduino.h"
#include <QMainWindow>
#include <QString>
#include <QSqlQueryModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino
    void ajouter(QString nom, QString id_p, QString date );
    QSqlQueryModel* afficher();

  
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;


    QByteArray data; // recuperation des donee

    Arduino A; // objet temporaire
};

#endif // MAINWINDOW_H

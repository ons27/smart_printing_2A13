#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
#include "fournisseurs.h"
=======
#include "employee.h"
#include"conge.h"
#include "equipements.h"
#include "interventions.h"
#include "commandes.h"
#include "client.h"
#include <QtXml>
#include <QFileDialog>
#include <QPdfWriter>
#include <QDesktopServices>
#include "arduinomov.h"
#include <QSqlQueryModel>
>>>>>>> 9cdc5de51a5e4b9e00fe648bc684815af01e3d83


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

    //****************CLIENT*****************//////////


    void on_HomeBtn_10_clicked();

    void on_DataBtn_21_clicked();

    void on_addeq_21_clicked();

    void on_HomeBtn_11_clicked();

    void on_DataBtn_22_clicked();

    void on_addeq_22_clicked();

    void on_HomeBtn_12_clicked();

    void on_DataBtn_23_clicked();

    void on_addeq_23_clicked();

    void on_HomeBtn_21_clicked();

    void on_DataBtn_24_clicked();

    void on_addeq_24_clicked();

    //void on_pushButton_2_clicked();

    void on_LogoutBtn_21_clicked();

    void on_LogoutBtn_22_clicked();

    void on_LogoutBtn_23_clicked();

    void on_LogoutBtn_24_clicked();
    void on_LogoutBtn_25_clicked();


    void on_buttonBox_7_accepted();

    void on_PdfBtn_12_clicked();
    void on_PdfBtn_30_clicked();





    void on_table_activated(const QModelIndex &index);

    void on_Psearch_4_textChanged(const QString &arg1);

    void on_Tri_IdE_2_clicked();

    void on_Tri_Taille_2_clicked();

    void on_Tri_Taille_3_clicked();

    void on_Tri_Taille_4_clicked();

    void on_buttonBox_2_clicked();

    void sendMail();

    void mailSent(QString) ;

    void on_Mailing_2_clicked();

    void on_PdfBtn_13_clicked();

    void on_sendBtn_6_clicked();

    void on_PdfBtn_14_clicked();

    void on_mailing_clicked();

    void on_PdfBtn_15_clicked();

    void on_PdfBtn_26_clicked();

    void on_PdfBtn_27_clicked();




    void on_HomeBtn_22_clicked();

    void on_PdfBtn_28_clicked();



//*****************


    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

    void on_pushButton_50_clicked();
    //void on_pushButton_2_clicked(); // bouton OFF
    void on_pushButton_47_clicked();

    void on_pushButton_46_clicked();































    //****************CLIENT*****************//////////


    void on_HomeBtn_clicked();

    void on_DataBtn_clicked();

    void on_addeq_clicked();

    void on_HomeBtn_2_clicked();

    void on_DataBtn_2_clicked();

    void on_addeq_2_clicked();

    void on_HomeBtn_4_clicked();

    void on_DataBtn_4_clicked();

    void on_addeq_3_clicked();

    void on_HomeBtn_5_clicked();

    void on_DataBtn_5_clicked();

    void on_addeq_4_clicked();

    void on_pushButton_2_clicked();

    void on_LogoutBtn_clicked();

    void on_LogoutBtn_2_clicked();

    void on_LogoutBtn_4_clicked();

    void on_LogoutBtn_5_clicked();

    void on_buttonBox_2_accepted();

    void on_PdfBtn_3_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_table_activated(const QModelIndex &index);

    void on_txtBtn_18_clicked();

    void on_txtBtn_6_clicked();

    void on_txtBtn_7_clicked();

    void on_txtBtn_8_clicked();

    void on_HomeBtn_8_clicked();

    void on_DataBtn_8_clicked();

    void on_addeq_8_clicked();

    void on_LogoutBtn_8_clicked();

    void on_lineEdit_12_textChanged(const QString &arg1);

    void on_Export_button_clicked();

    void on_trierbutton_clicked();

    void on_trierNbutton_clicked();

    void on_trierAbutton_clicked();



    void on_PdfBtn_29_clicked();

    void on_PdfBtn_31_clicked();

private:
    QByteArray set; // variable contenant les données reçues

    Ui::MainWindow *ui;
<<<<<<< HEAD
    fournisseurs f;
    /*produit p;*/


=======
    Employee e;
    Client cs;

    Conge c ;
    equipement ee;
    interventions i;
    commandes cc;
    int it=0;
    int wait=0;
    int inc=0;
    ArduinoB A; // objet temporaire
>>>>>>> 9cdc5de51a5e4b9e00fe648bc684815af01e3d83
};
#endif // MAINWINDOW_H

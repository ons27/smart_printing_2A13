#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee.h"
#include"conge.h"
#include "arduinor.h"
#include "equipements.h"
#include "interventions.h"
#include "commandes.h"
#include "fournisseurs.h"
#include "client.h"
#include <QtXml>
#include <QFileDialog>
#include <QPdfWriter>
#include <QDesktopServices>
#include "arduinomov.h"
#include <QSqlQueryModel>
#include <QString>



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

    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

    void on_pushButton_50_clicked();
    //void on_pushButton_2_clicked(); // bouton OFF
    void on_pushButton_47_clicked();

    void on_pushButton_46_clicked();

    //****************CLIENT*****************//////////

    //****************FOURNISSEURS*****************//////////

    void updateR_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino
    void ajouter(QString nom, QString id_p, QString date );
    QSqlQueryModel* afficher();


    void on_pushButtonR_clicked();

    void on_HomeBtn_24_clicked();

    void on_DataBtn_25_clicked();

    void on_addeq_25_clicked();

    void on_HomeBtn_25_clicked();

    void on_DataBtn_26_clicked();

    void on_addeq_26_clicked();

    void on_HomeBtn_26_clicked();

    void on_DataBtn_27_clicked();

    void on_addeq_27_clicked();

    void on_HomeBtn_27_clicked();

    void on_DataBtn_28_clicked();

    void on_addeq_28_clicked();

    void on_pushButton_51_clicked();

    void on_LogoutBtn_26_clicked();

    void on_LogoutBtn_27_clicked();

    void on_LogoutBtn_28_clicked();

    void on_LogoutBtn_29_clicked();

    void on_buttonBox_10_accepted();

    void on_PdfBtn_34_clicked();

    void on_pushButton_52_clicked();

    //void on_pushButton_4_clicked();

    void on_table_7_activated(const QModelIndex &index);

    void on_txtBtn_18_clicked();

    void on_txtBtn_6_clicked();

    void on_txtBtn_7_clicked();

    void on_txtBtn_8_clicked();

    void on_HomeBtn_23_clicked();

    void on_DataBtn_29_clicked();

    void on_addeq_29_clicked();

    void on_LogoutBtn_30_clicked();

    void on_lineEdit_89_textChanged(const QString &arg1);

    void on_Export_button_clicked();

    void on_trierbutton_clicked();

    void on_trierNbutton_clicked();

    void on_trierAbutton_clicked();






















    //****************FOURNISSEURS*****************//////////


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



    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

   // void on_table_doubleClicked(const QModelIndex &index);






    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    //void on_textEdit_textChanged();
   // void on_lineEdit_textChanged(const QString &arg1);

    void on_HomeBtn_15_clicked();

    void on_PdfBtn_4_clicked();

    void on_PdfBtn_clicked();

    void on_PdfBtn_2_clicked();

    void on_DataBtn_15_clicked();

    void on_addeq_15_clicked();




    void on_pushButton_9_clicked();

   // void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

   // void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_15_clicked();

    void on_HomeBtn_6_clicked();

    void on_DataBtn_6_clicked();

    void on_addeq_6_clicked();

    void on_PdfBtn_7_clicked();

    void on_PdfBtn_8_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_LogoutBtn_6_clicked();

    void on_SettingsBtn_15_clicked();

    void on_pushButton_17_clicked();

    void on_DataBtn_33_clicked();

    void on_addeq_33_clicked();

    void on_PdfBtn_57_clicked();

    void on_HomeBtn_34_clicked();

    void on_DataBtn_34_clicked();

    void on_addeq_34_clicked();

    void on_PdfBtn_58_clicked();

    void on_HomeBtn_35_clicked();

    void on_DataBtn_35_clicked();

    void on_addeq_35_clicked();

    void on_PdfBtn_63_clicked();

    void on_HomeBtn_36_clicked();

    void on_DataBtn_36_clicked();

    void on_addeq_36_clicked();

    void on_PdfBtn_64_clicked();

    void on_PdfBtn_59_clicked();

    void on_pushButton_77_clicked();

    void on_table_13_activated(const QModelIndex &index);

    void on_PdfBtn_60_clicked();

    void on_PdfBtn_61_clicked();

    void on_PdfBtn_62_clicked();

    void on_pushButton_79_clicked();

    void on_lineEdit_111_textChanged(const QString &arg1);


    void on_pushButton_78_clicked();

    void on_pushButton_80_clicked();

    void on_buttonBox_11_accepted();

    void on_PdfBtn_65_clicked();

    void on_table_14_activated(const QModelIndex &index);

    void on_pushButton_83_clicked();

    void on_pushButton_84_clicked();

    void on_pushButton_85_clicked();

    void on_pushButton_82_clicked();

    void on_HomeBtn_9_clicked();

    void on_DataBtn_11_clicked();

    void on_addeq_11_clicked();

    void on_DataBtn_9_clicked();

    void on_addeq_9_clicked();

    void on_DataBtn_10_clicked();

    void on_addeq_10_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_38_clicked();

    void on_PdfBtn_11_clicked();

    void on_qr_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_39_clicked();

    void on_buttonBox_5_accepted();

    void on_LogoutBtn_11_clicked();

    void on_LogoutBtn_10_clicked();

    void on_LogoutBtn_9_clicked();

    void on_LogoutBtn_33_clicked();

    void on_LogoutBtn_34_clicked();

    void on_LogoutBtn_35_clicked();

    void on_LogoutBtn_36_clicked();

    void on_table_3_activated(const QModelIndex &index);

    void on_PdfBtn_29_clicked();

    void on_PdfBtn_31_clicked();

    void on_PdfBtn_32_clicked();

    void on_PdfBtn_33_clicked();

    void on_PdfBtn_35_clicked();

    void on_PdfBtn_36_clicked();

    void on_PdfBtn_37_clicked();

    void on_tableViewR_activated(const QModelIndex &index);

    void on_HomeBtn_28_clicked();

private:
    QByteArray set; // variable contenant les données reçues

    Ui::MainWindow *ui;
    Employee e;
    Client cs;

    Conge c ;
    equipement ee;
    interventions i;
    commandes cc;
    fournisseurs f;
    int it=0;
    int wait=0;
    int inc=0;
    ArduinoB A; // objet temporaire
    QByteArray data; // recuperation des donee

    ArduinoR S; // objet temporaire
};
#endif // MAINWINDOW_H


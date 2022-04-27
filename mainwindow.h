#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee.h"
#include"conge.h"
#include "equipements.h"
#include "interventions.h"
#include "produit.h"
#include "arduino.h"

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

    void on_buttonBox_6_accepted();

    void on_pushButton_37_clicked();

    void on_pushButton_38_clicked();

    void on_table_3_activated(const QModelIndex &index);

    void on_recherche_textChanged(const QString &arg1);

    void on_recherche2_textChanged(const QString &arg1);

    void on_recherche3_textChanged(const QString &arg1);

    void on_tri_quantite_clicked();

    void on_tri_categorie_clicked();

    void on_tri_id_clicked();

    void on_pdf_clicked();

    void on_Excel_clicked();

    void on_statistics_4_clicked();

    void on_statCategorie_4_clicked();

    void on_pushButton_86_clicked();

    void on_HomeBtn_26_clicked();

    void on_DataBtn_26_clicked();

    void on_addeq_26_clicked();

    void on_HomeBtn_22_clicked();

    void on_DataBtn_22_clicked();

    void on_addeq_22_clicked();

    void on_HomeBtn_10_clicked();

    void on_DataBtn_10_clicked();

    void on_addeq_10_clicked();


    void on_LogoutBtn_26_clicked();
     void update_label();

     void on_pushButton_42_clicked();

     void on_pushButton_95_clicked();

     void on_pushButton_94_clicked();

private:
    Ui::MainWindow *ui;
    Employee e;
    Conge c ;
    equipement ee;
    interventions i;
    produit p;
    Arduino A;
    QByteArray data;
};
#endif // MAINWINDOW_H


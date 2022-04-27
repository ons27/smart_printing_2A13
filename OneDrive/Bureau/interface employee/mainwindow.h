#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee.h"
#include"conge.h"

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

private:
    Ui::MainWindow *ui;
    Employee e;
    Conge c ;
};
#endif // MAINWINDOW_H


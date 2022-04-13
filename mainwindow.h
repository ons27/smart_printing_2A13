#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fournisseurs.h"
#include "produit.h"

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



private:
    Ui::MainWindow *ui;
    fournisseurs f;
    /*produit p;*/


};
#endif // MAINWINDOW_H

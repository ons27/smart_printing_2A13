#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    //void on_PdfBtn_3_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_table_activated(const QModelIndex &index);



    void on_recherche_textChanged(const QString &arg1);

    void on_recherche2_textChanged(const QString &arg1);

    void on_tri_categorie_clicked();

    void on_tri_id_clicked();

    void on_tri_quantite_clicked();



private:
    Ui::MainWindow *ui;
    produit p;
};
#endif // MAINWINDOW_H

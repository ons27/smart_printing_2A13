#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QTranslator>
#include <QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator t;

        QStringList languages;
        languages<< "English"<<"French";
        QString lang =QInputDialog::getItem(NULL,"Select your language","Language",languages);
        if(lang=="English")
        {
            t.load(":/english.qm");
        }
        if(lang!="French")
        {
            a.installTranslator(&t);
        }
    Connection c;
    c.createconnect();
    MainWindow w;
    w.show();
    return a.exec();
}

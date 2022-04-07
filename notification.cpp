#include "notification.h"

notification::notification()
{

}
void notification::notification_system()
{
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon();
    notifyIcon->show();
    notifyIcon->showMessage("Product Managment","Product added",QSystemTrayIcon::Information,15000);
}

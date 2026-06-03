#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "checkindialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCheckIn_clicked()
{
    CheckInDialog *checkInDialog = new CheckInDialog(this);     //Form a CheckInDialog object

    checkInDialog->setIsCheckInPressed(true);

    auto ret = checkInDialog->exec();       //Start CheckInDialog

    if(ret == QDialog :: Accepted)          //Control point
    {
        qDebug() << "Okay Clicked";

    }
    else
    {
        qDebug() << "Cancel Clicked";

    }
    /**
     * If "CheckInDialog *checkInDialog = new CheckInDialog(this);" taking "this" pointer,
     * checkInDialog dynamic object would be destructed. There is a parent - child connection
     * for the dialog screens (mainwindow - checkindialog). Qt allows this handy function.
     * But if it is not used, use classically "delete checkInDialog;"
     */
}


void MainWindow::on_pushButtonCheckOut_clicked()
{
    CheckInDialog *checkInDialog = new CheckInDialog(this);     //Form a CheckInDialog object

    checkInDialog->setIsCheckInPressed(false);

    auto ret = checkInDialog->exec();       //Start CheckInDialog

    if(ret == QDialog :: Accepted)          //Control point
    {
        qDebug() << "Okay Clicked";

    }
    else
    {
        qDebug() << "Cancel Clicked";

    }
}


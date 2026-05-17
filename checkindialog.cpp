#include "checkindialog.h"
#include "ui_checkindialog.h"

CheckInDialog::CheckInDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CheckInDialog)
{
    ui->setupUi(this);
}

CheckInDialog::~CheckInDialog()
{
    delete ui;
}

void CheckInDialog::on_pushButtonOkay_clicked()
{
    accept();
}


void CheckInDialog::on_pushButtonCancel_clicked()
{
    reject();
}


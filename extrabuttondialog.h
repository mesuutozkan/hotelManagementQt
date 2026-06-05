#ifndef EXTRABUTTONDIALOG_H
#define EXTRABUTTONDIALOG_H

#include <QDialog>

namespace Ui {
class ExtraButtonDialog;
}

class ExtraButtonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExtraButtonDialog(QWidget *parent = nullptr);
    ~ExtraButtonDialog();

private slots:
    void on_pushButtonOkay_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::ExtraButtonDialog *ui;
};

#endif // EXTRABUTTONDIALOG_H

#include "cloudwaredialog.h"
#include "ui_cloudwaredialog.h"

CloudwareDialog::CloudwareDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CloudwareDialog)
{
    ui->setupUi(this);
}

CloudwareDialog::~CloudwareDialog()
{
    delete ui;
}

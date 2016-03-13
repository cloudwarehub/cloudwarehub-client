#ifndef CLOUDWAREDIALOG_H
#define CLOUDWAREDIALOG_H

#include <QDialog>
#include <libde265/de265.h>

namespace Ui {
class CloudwareDialog;
}

class CloudwareDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CloudwareDialog(QWidget *parent = 0);
    ~CloudwareDialog();
    int wid; /* x11 window id */

private:
    Ui::CloudwareDialog *ui;
};

#endif // CLOUDWAREDIALOG_H

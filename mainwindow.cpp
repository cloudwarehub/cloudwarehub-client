#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QtNetwork"
#include "cloudwaredialog.h"
#include "cip_protocol.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    qDebug("%d\n", e->x());
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    qDebug("%d\n", e->x());
}

void MainWindow::windowCreate(cip_event_window_create_t *ev)
{
    CloudwareDialog *window = new CloudwareDialog(this);
    this->windows[ev->wid] = window;
    window->wid = ev->wid;
    window->setGeometry(ev->x, ev->y, ev->width, ev->height);
    if (ev->bare)
        window->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

void MainWindow::windowHide(cip_event_window_hide_t *ev)
{
    CloudwareDialog *window = (CloudwareDialog*)this->windows[ev->wid];
    window->hide();
}

void MainWindow::windowDestroy(cip_event_window_destroy_t *ev)
{
    CloudwareDialog *window = (CloudwareDialog*)this->windows[ev->wid];
    window->close();
}

void MainWindow::windowShow(cip_event_window_show_t *ev)
{
    CloudwareDialog *window = (CloudwareDialog*)this->windows[ev->wid];
    if (ev->bare)
        window->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    window->show();
}

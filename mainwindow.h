#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include "cip_protocol.h"
#include "cloudwaredialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QMap<int, CloudwareDialog*> windows;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

public slots:
    void windowCreate(cip_event_window_create_t *ev);
    void windowDestroy(cip_event_window_destroy_t *ev);
    void windowShow(cip_event_window_show_t *ev);
    void windowHide(cip_event_window_hide_t *ev);
    void renderFrame(cip_event_window_frame_t *ev, char *data);

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H

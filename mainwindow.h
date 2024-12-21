//
// Created by LZ on 24-8-20.
//

#ifndef AOE_MAINWINDOW_H
#define AOE_MAINWINDOW_H

#include <QMainWindow>
#include "qcanvas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
    friend QCanvas;
public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
private slots:
    void Run();
    void Save();
};


#endif //AOE_MAINWINDOW_H

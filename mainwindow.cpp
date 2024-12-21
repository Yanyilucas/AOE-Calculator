//
// Created by LZ on 24-8-20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->action_run_project,&QAction::triggered,this,&MainWindow::Run);
    connect(ui->action_save,&QAction::triggered,this,&MainWindow::Save);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);  // 设置为平面风格，更现代
    // 使用 QColor 设置颜色
    QColor textColor = QColor(28, 28, 28);
    QColor backgroundColor = QColor(207, 207, 207);
    QColor borderColor = QColor(232, 232, 232);

    // 转换 QColor 为样式表字符串格式
    QString styleSheet =QString("QLCDNumber { color: %1; background-color: %2; border: 2px solid %3; }")
            .arg(textColor.name())         // 颜色的十六进制表示
            .arg(backgroundColor.name())
            .arg(borderColor.name());
    ui->lcdNumber->setStyleSheet(styleSheet);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::Run() {
    AOENet*  AOE=new AOENet(ui->Canvas->shapes);
    bool isValid=AOE->TopologySort();
    QCanvas* canvas=ui->Canvas;
    ui->lcdNumber->display(0);
    ui->tabNode->setRowCount(0);
    ui->tabLine->setRowCount(0);
    if(isValid)
    {
        ui->checkBox->setChecked(true);
        AOE->updateEST();
        AOE->updateLST();
        AOENode* finder=AOE->Thead;
        //填表
        for(;finder!= nullptr;finder=finder->next)
        {
            int row=ui->tabNode->rowCount();
            //finder->Frontend_node->TOPONum=NodeNo;
            ui->tabNode->insertRow(row);
            ui->tabNode->setItem(row,0,new QTableWidgetItem(QString::number(finder->Frontend_node->TOPONum)));
            ui->tabNode->setItem(row,1,new QTableWidgetItem(QString::number(finder->EST)));
            ui->tabNode->setItem(row,2,new QTableWidgetItem(QString::number(finder->LST)));

            if(finder->next== nullptr)
                ui->lcdNumber->display(finder->LST);  // 显示示例数字
        }
        for(AOENode* pN=AOE->Thead;pN;pN=pN->next)
            for(AOELine* pl=pN->LinesOut;pl;pl=pl->next)
            {
                int r=ui->tabLine->rowCount();
                ui->tabLine->insertRow(r);
                ui->tabLine->setItem(r,0,
                                     new QTableWidgetItem(QString::number(pN->Frontend_node->TOPONum)));
                ui->tabLine->setItem(r,1,
                                     new QTableWidgetItem(QString::number(pl->To->Frontend_node->TOPONum)));
                int slack= pl->To->LST- pN->EST -pl->length;
                ui->tabLine->setItem(r,2,
                                     new QTableWidgetItem(QString::number(slack)));
                if(slack==0) {
                    ui->tabLine->setItem(r, 3,
                                         new QTableWidgetItem(QString("是")));
                    pl->Frontend_line->isKeyPath= true;
                }
            }
    }
    else
    {
        ui->checkBox->setChecked(false);
    }
    delete AOE;
    ui->Canvas->Runningmode= true;
    ui->Canvas->update();
}

void MainWindow::Save() {
        //保存图片.
        //QString currentPath = QDir::currentPath();  // 获取当前工作目录
        //qDebug() << "Current directory:" << currentPath;

        QImage image(ui->Canvas->size(), QImage::Format_ARGB32);
        QPainter painter(&image);
        ui->Canvas->render(&painter);  // 将widget内容渲染到QImage中

        image.save("AOE.png");  // 保存QImage到文件


}

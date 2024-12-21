//
// Created by LZ on 24-8-20.
//

#ifndef QCANVAS_H
#define QCANVAS_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include<QContextMenuEvent>
#include <QMenu>
#include <QDebug>
#include <QList>
#include <QEvent>
#include <QMouseEvent>


#include "Dialog.h"
#include "AOE.h"
class MainWindow;
class QCanvas : public QWidget {
Q_OBJECT
    friend MainWindow;
public:
    // 构造函数，接受一个父指针，默认为空指针
    explicit QCanvas(QWidget *parent = nullptr);
    ~QCanvas();
    QAction CanvasAct_new=QAction("新建事件", this);
    QAction CanvasAct_clear=QAction("清空工程", this);
    QAction CanvasAct_delete=QAction("删除事件", this);
    QAction CanvasAct_deleteline=QAction("删除活动", this);
    QAction CanvasAct_edit=QAction("编辑活动时长", this);
    QAction CanvasAct_connect=QAction("联结事件", this);
protected:

    // 重写paintEvent以绘制画布内容
    void paintEvent(QPaintEvent *event) override;
    QColor background=QColor(250, 240, 230);
private:
    void contextMenuEvent(QContextMenuEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;
    void ShapeDel();
    void LineDel();



    // 其他私有变量，比如存储图形对象的列表
    QList<Shape*> shapes;
    Shape* currShape= nullptr;//当前选中的节点
    QList<Line*> lines;
    Line* currLine = nullptr;//当前选中线段
    QPoint lastMousePos;

    bool Runningmode= false;//是否在显示运行结果



private slots:
    void CAnew(const QPoint& point);
    void CAclear();
    void CAdelete();
    void CAedit();
    void CAconnect(const QPoint& point);


};

#endif // QCANVAS_H



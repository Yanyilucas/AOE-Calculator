//
// Created by LZ on 24-8-20.
//

#include "qcanvas.h"

QCanvas::QCanvas(QWidget *parent) : QWidget(parent){
    //初始化画布内容
    connect(&CanvasAct_clear, &QAction::triggered, this, &QCanvas::CAclear);
    connect(&CanvasAct_delete, &QAction::triggered, this, &QCanvas::CAdelete);
    connect(&CanvasAct_edit, &QAction::triggered, this, &QCanvas::CAedit);
    connect(&CanvasAct_deleteline, &QAction::triggered, this, &QCanvas::CAdelete);
}

void QCanvas::paintEvent(QPaintEvent *event) {
    //qDebug()<<"currShape==Null : "<< (currShape== nullptr)<<"     currLine==Null : "<< (currLine== nullptr);
    QPainter painter(this);
    painter.fillRect(rect(), background);  // 将背景填充为白色

    for(Line* &line:lines)
        line->draw(painter, Runningmode);

    for (Shape* &shape : shapes)
        shape->draw(painter, Runningmode);
    painter.end();
}

void QCanvas::contextMenuEvent(QContextMenuEvent *event) {
    bool isInNode= false;
    bool isNearLine=false;
    for(Shape* &shape:shapes)
        if(shape->contains(event->pos()))
        {
            currShape=shape;
            isInNode= true;
            break;
        }
    if(!isInNode)
        for(Line* &line:lines)
            if(line->nearEnough(event->pos()))
            {
                currLine=line;
                isNearLine= true;
                break;
            }
    //首先判断,选中栏目是节点还是线段还是空

    QMenu contextMenu(this);
    if(!isInNode) {//如果没有选中节点
        if(isNearLine)
        {
            if(currLine->ToEND) {//在线段附近选择,有编辑连线,删除连线操作
                //编辑连线
                contextMenu.addAction(&CanvasAct_edit);
                //删除连线
                contextMenu.addAction(&CanvasAct_deleteline);
                // 当 CanvasAct_edit 被触发时设置标记
            }
            else
            {
                //在连线过程中,在线段内右键
                QMutableListIterator<Line *> itLine(currLine->FromEND->LinesOut);
                while (itLine.hasNext()) {
                    Line *oline = itLine.next();
                    if (oline == currLine)
                        itLine.remove();

                }
                QMutableListIterator<Line *> itLines(lines);
                while (itLines.hasNext()) {
                    Line *oline = itLines.next();
                    if (oline == currLine) {
                        delete oline;//这是同一个对象,删除一次即可
                        itLines.remove();
                    }
                }
                currLine= nullptr;
                update();
            }
        }
        else//新建节点
        {
            contextMenu.addAction(&CanvasAct_new);
            disconnect(&CanvasAct_new, &QAction::triggered, this, nullptr);//先断开所有联结
            connect(&CanvasAct_new, &QAction::triggered, this, [this, event] {
            CAnew(event->pos());
            });
        }
    }
    else {
        //连接节点
            if(currLine!= nullptr && currLine->ToEND== nullptr)
            {
                    //在连线过程中,在节点内右键
                    QMutableListIterator<Line *> itLine(currLine->FromEND->LinesOut);
                    while (itLine.hasNext()) {
                        Line *oline = itLine.next();
                        if (oline == currLine)
                            itLine.remove();

                    }
                    QMutableListIterator<Line *> itLines(lines);
                    while (itLines.hasNext()) {
                        Line *oline = itLines.next();
                        if (oline == currLine) {
                            delete oline;//这是同一个对象,删除一次即可
                            itLines.remove();
                        }
                    }
                currLine= nullptr;
                update();
            }

                contextMenu.addAction(&CanvasAct_connect);
                disconnect(&CanvasAct_connect, &QAction::triggered, this, nullptr);//先断开所有联结
                connect(&CanvasAct_connect, &QAction::triggered, this, [this, event] {
                            CAconnect(event->pos());
                        }
                );

                //删除节点
                contextMenu.addAction(&CanvasAct_delete);

    }

    contextMenu.addAction(&CanvasAct_clear);//清空节点
    QAction* QAct= contextMenu.exec(event->globalPos());
    if(QAct== nullptr)
    {
        currLine= nullptr;
        currShape= nullptr;
    }
}

void QCanvas::CAconnect(const QPoint& point) {
    Runningmode= false;
    QPoint From=currShape->rect.center();
    Line* floatLine=new Line(From);
    floatLine->setEnd(point);
    currLine=floatLine;

    floatLine->FromEND=currShape;
    floatLine->ToEND= nullptr;
    currShape->LinesOut.append(currLine);

    lines.append(floatLine);
    update();
}



void QCanvas::CAnew(const QPoint &center) {
    Runningmode= false;
    int R=Shape::R;
    QRect circleRect(center.x() - R, center.y() - R, R * 2, R * 2);
    Shape* circleShape=new Shape(circleRect);
    shapes.append(circleShape);
    update();

}

void QCanvas::CAclear() {
    Runningmode= false;
    QMutableListIterator<Line*> itLine(lines);
    while (itLine.hasNext()) {
        Line* line = itLine.next();
        delete line;  // 释放指针所指向的对象
        itLine.remove();  // 从 QList 中删除指针
    }
    currLine= nullptr;
    QMutableListIterator<Shape*> itShape(shapes);
    while (itShape.hasNext()) {
        Shape* shape = itShape.next();
        delete shape;  // 释放指针所指向的对象
        itShape.remove();  // 从 QList 中删除指针
    }
    currShape= nullptr;
    update();
}

void QCanvas::CAdelete() {
    //线段删除逻辑: 1.清理两端节点的入度与出度 2:删除此线段
    //节点删除逻辑: 1.删除入度与出度线段关联节点的线段QList;2.删除入度与出度线段;3.删除节点
    Runningmode= false;
    if(currShape!= nullptr)
        ShapeDel();
    if(currLine!= nullptr)
        LineDel();
    currShape = nullptr;
    currLine = nullptr;
    update();
}

void QCanvas::mousePressEvent(QMouseEvent *event) {


    QWidget::mousePressEvent(event);
    Qt::MouseButtons buttons = event->buttons();
    if(!(buttons && buttons==Qt::LeftButton))return;//如果不是左键按下,无视
    //DONE :在鼠标空白处拖拽导致程序崩溃
    //qDebug()<<"[INFO]鼠标左击事件";
    //如果当前没有在联结线段,则选中节点//不需要选中线段进行反显
    if(currLine== nullptr) {
        //qDebug()<<"currLine为空";
        for (int i = 0; i < shapes.size(); i++) {
            Shape *shape = shapes.at(i);
            //qDebug()<<"鼠标在节点范围内";
            if (shape->contains(event->pos())) {
                if (currShape == nullptr || !currShape->isSelected) {
                    shape->setSelected(true);
                    shapes.removeAt(i);
                    shapes.push_back(shape);
                    currShape = shape;
                    lastMousePos = event->pos();
                }
            } else
                shape->setSelected(false);
        }
    }
    else
    {
        //qDebug()<<"currLine不为空";
        bool hasFound= false;
        for(Shape* &shape:shapes)
            if (shape->contains(event->pos())) {
                //qDebug()<<"鼠标在节点范围内";
                if(currLine->setShapeEnd(shape)) {
                    currLine->ToEND = shape;
                    shape->LinesIN.append(currLine);
                    hasFound= true;
                    break;
                }
            }

        if(!hasFound){//没有吸附到最近节点/最近节点已经有连接=>删除该线段及其起点的出度,在lines中删除
            //qDebug()<<"没有hasFound";
            QMutableListIterator<Line *> itLine(currLine->FromEND->LinesOut);
            while (itLine.hasNext()) {
                Line *oline = itLine.next();
                if(oline==currLine)
                    itLine.remove();

            }
            QMutableListIterator<Line *> itLines(lines);
            while (itLines.hasNext()) {
                Line *oline = itLines.next();
                if(oline==currLine)
                {
                    delete oline;//这是同一个对象,删除一次即可
                    itLines.remove();
                }
            }
        }
        currLine= nullptr;
    }
    update();
}

void QCanvas::mouseMoveEvent(QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);
    if(currLine!= nullptr && currLine->ToEND== nullptr)
        currLine->setEnd(event->pos());

    if(currShape!= nullptr && currShape->isSelected) {
        QPoint offset = event->pos() - lastMousePos;  // 计算偏移量
        currShape->moveBy(offset);  // 移动图形

        for(Line* &line:currShape->LinesOut)
        {
            line->setBegin(currShape->rect.center());
            line->setShapeEnd(line->ToEND);
        }

        for(Line* &line:currShape->LinesIN)
            line->setShapeEnd(currShape);


        lastMousePos = event->pos();  // 更新 lastMousePos 为当前鼠标位置
    }
    update();

}

void QCanvas::mouseReleaseEvent(QMouseEvent *event) {

    if(currShape== nullptr)return;//当前没有选中,不进行操作.
    QWidget::mouseReleaseEvent(event);
    currShape->setSelected(false);
    currShape= nullptr;
    update();
}

QCanvas::~QCanvas() {
   CAclear();
}

void QCanvas::ShapeDel() {
    QMutableListIterator<Shape *> itShape(shapes);
    while (itShape.hasNext()) {
        Shape *shape = itShape.next();
        if (shape == currShape) {
            QMutableListIterator<Line *> itLine(lines);//安全遍历,防止跳过
            while (itLine.hasNext()) {
                Line *line = itLine.next();
                if (line->FromEND == currShape || line->ToEND == currShape) {
                    //将与line关联节点的Shape清理干净
                    bool flag = line->FromEND == currShape;
                    Shape *relation_shape = (flag) ? line->ToEND : line->FromEND;
                    if (flag) {
                        QMutableListIterator<Line *> ioit(relation_shape->LinesIN);

                        while (ioit.hasNext()) {
                            Line *linein = ioit.next();
                            if (linein == line) {
                                ioit.remove();
                                break;
                            }
                        }
                    } else {
                        QMutableListIterator<Line *> ioit(relation_shape->LinesOut);

                        while (ioit.hasNext()) {
                            Line *lineout = ioit.next();
                            if (lineout == line) {
                                ioit.remove();
                                break;
                            }
                        }
                    }
                    delete line;
                    itLine.remove();  // 删除符合条件的线段
                }
            }
            delete shape;
            itShape.remove();
            break;
        }
    }
}

void QCanvas::LineDel() {
    QMutableListIterator<Line *> itLine(lines);//安全遍历,防止跳过
    while (itLine.hasNext()) {
        Line *line = itLine.next();
        Shape* from=line->FromEND;
        Shape* to = line->ToEND;
        if(line==currLine) {
            QMutableListIterator<Line *> oit(from->LinesOut);

            while (oit.hasNext()) {
                Line *lineout = oit.next();
                if (lineout == currLine) {
                    oit.remove();
                    break;
                }
            }
            QMutableListIterator<Line *> iit(to->LinesIN);

            while (iit.hasNext()) {
                Line *linein = iit.next();
                if (linein == currLine) {
                    iit.remove();
                    break;
                }
            }
            delete line;
            itLine.remove();
            break;
        }
    }
}

void QCanvas::CAedit() {
    //编辑线段上的数字
    Runningmode= false;
    if(currLine!= nullptr)
    {
        Dialog dialog(currLine, this);
        dialog.exec();
        currLine= nullptr;
    }
    update();
}



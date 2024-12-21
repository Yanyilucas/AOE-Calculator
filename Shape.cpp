//
// Created by LZ on 24-8-20.
//

#include "Shape.h"

Shape::Shape(const QRect &rect) : rect(rect), isSelected(false) {}

void Shape::draw(QPainter &painter, bool running) const {
    //running mode:默认情况下为操作者模式 false.
    //当为true时, 1.标数字序号 2.若不能形成拓扑排序,则环中节点标红

    if (isSelected) {
        QColor selectedColor(255, 127, 80); // 珊瑚色
        painter.setPen(QPen(selectedColor, 3, Qt::SolidLine));
        painter.setBrush(QBrush(selectedColor));
    } else {
        if(!running || (TOPONum)) {
            QColor unselectedColor_frame(70, 130, 180); // 钢蓝色
            QColor unselectedColor_fill(187, 255, 255);
            painter.setBrush(QBrush(unselectedColor_fill));
            painter.setPen(QPen(unselectedColor_frame, 3, Qt::SolidLine));
        }
        else
        {
                QColor unselectedColor_frame(255, 0, 0); // 红
                QColor unselectedColor_fill(255, 64, 64);
                painter.setBrush(QBrush(unselectedColor_fill));
                painter.setPen(QPen(unselectedColor_frame, 3, Qt::SolidLine));

        }

    }
    painter.drawEllipse(rect);
    if( running && TOPONum)
    {
        QFont font;
        font.setFamily("Arial");
        font.setPointSize(16);
        font.setBold(true);
        painter.setFont(font);
        // 开启抗锯齿
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);
        // 设置文本颜色
        painter.setPen(Qt::white);
        // 绘制文本，居中对齐
        painter.drawText(rect, Qt::AlignCenter, QString::number(TOPONum));
    }
}

bool Shape::contains(const QPoint &point) const {
    QPoint center = rect.center();
    int radius =(rect.height()+ rect.width()) / 4;
    return (point.x()-center.x())*(point.x()-center.x())+
                   (point.y()-center.y())*(point.y()-center.y())<= radius*radius;
}

void Shape::moveBy(const QPoint &offset)  {
    rect.translate(offset);
}

void Shape::setSelected(bool selected) {
        isSelected = selected;
}

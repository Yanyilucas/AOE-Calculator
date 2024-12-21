//
// Created by LZ on 24-8-20.
//

#ifndef AOE_SHAPE_H
#define AOE_SHAPE_H


#include <QPainter>
#include <QRect>
#include<QPen>
#include<QBrush>
#include <QColor>
#include <QList>

class Line;
class Shape {
public:
    explicit Shape(const QRect &rect);

    // 绘制图形
    void draw(QPainter &painter, bool b) const ;

    // 判断点是否在图形内
    bool contains(const QPoint &point) const;

    // 移动图形
    void moveBy(const QPoint &offset);

    // 设置选中状态
    void setSelected(bool selected);

    bool isSelected;
    QRect rect;
    QList<Line*>LinesIN;
    QList<Line*>LinesOut;
    int TOPONum=0;
    constexpr static int R=20;
};



#endif //AOE_SHAPE_H

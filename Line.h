//
// Created by LZ on 24-8-21.
//

#ifndef AOE_LINE_H
#define AOE_LINE_H
#include <QPoint>
#include <QPainter>
#include <string>
#include<cmath>
#include <QDebug>
#include "Shape.h"
class Line {
private:
    QPoint From;
    QPoint To;
    int length=1;


    constexpr const static double validDisp=5.0;
    constexpr const static int arrowSize=10;  // 箭头的大小
public:
    Shape* FromEND;
    Shape* ToEND;
    bool isKeyPath= false;
    explicit Line(const QPoint& start);
    void draw(QPainter &painter, bool b);
    void setBegin(const QPoint& beg);
    void setEnd(const QPoint& end);
    bool setShapeEnd(Shape* shape);
    bool nearEnough(const QPoint& point);

    int getlength();
    void setlength(int len);
    void drawlength(QPainter& painter);
    static void drawArrow(QPainter& painter, const QPointF& start, const QPointF& end) ;
    static double pointToLineDistance(const QPointF& p, const QPointF& p1, const QPointF& p2) ;
};


#endif //AOE_LINE_H

//
// Created by LZ on 24-8-21.
//

#include "Line.h"
Line::Line(const QPoint& start) : From(start), To(start) {
    FromEND=ToEND= nullptr;
}

void Line::draw(QPainter &painter, bool running) {
        //running 为运行模式,若打开,关键路径标绿
        QColor unselectedColor_frame= (running && isKeyPath)? QColor(0, 255, 127):QColor(70, 130, 180);
        //QColor unselectedColor_fill(187, 255 ,255);
        painter.setBrush(QBrush(unselectedColor_frame));
        painter.setPen(QPen(unselectedColor_frame, 2, Qt::SolidLine));
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);


    painter.drawLine(From, To);
    drawArrow(painter,From,To);
    if(ToEND!= nullptr)
        drawlength(painter);
}

void Line::setEnd(const QPoint& end) {
    To = end;
}

double Line::pointToLineDistance(const QPointF& p, const QPointF& p1, const QPointF& p2) {
    double x0 = p.x(), y0 = p.y();
    double x1 = p1.x(), y1 = p1.y();
    double x2 = p2.x(), y2 = p2.y();

    // 计算向量 p1p2 和 p1p 的向量点积
    double dx = x2 - x1;
    double dy = y2 - y1;
    double t = ((x0 - x1) * dx + (y0 - y1) * dy) / (dx * dx + dy * dy);

    if (t < 0) {
        // 点 p 的投影在 p1 外，返回 p 到 p1 的距离
        return std::sqrt(std::pow(x0 - x1, 2) + std::pow(y0 - y1, 2));
    } else if (t > 1) {
        // 点 p 的投影在 p2 外，返回 p 到 p2 的距离
        return std::sqrt(std::pow(x0 - x2, 2) + std::pow(y0 - y2, 2));
    } else {
        // 点 p 的投影在线段 p1p2 上，返回点到线段的垂直距离
        double numerator = std::abs(dy * x0 - dx * y0 + x2 * y1 - y2 * x1);
        double denominator = std::sqrt(dx * dx + dy * dy);
        return numerator / denominator;
    }
}


void Line::drawArrow(QPainter &painter, const QPointF &start, const QPointF &end) {
    double angle = std::atan2(end.y() - start.y(), end.x() - start.x());

    // 计算箭头的三个顶点：终点、左翼、右翼
    QPointF arrowP1 = end - QPointF(std::cos(angle - M_PI / 6) * arrowSize,
                                    std::sin(angle - M_PI / 6) * arrowSize);
    QPointF arrowP2 = end - QPointF(std::cos(angle + M_PI / 6) * arrowSize,
                                    std::sin(angle + M_PI / 6) * arrowSize);

    // 创建一个三角形（箭头）的 QPolygonF
    QPolygonF arrowHead;
    arrowHead << end << arrowP1 << arrowP2;

    // 使用 QPainter 绘制填充的三角形箭头
    painter.drawPolygon(arrowHead);
}

bool Line::setShapeEnd(Shape* shape) {
    QPointF O=shape->rect.center();
    //处理重复起点与终点的清空,
    if(FromEND==shape)return false;
    for(Line* &line:shape->LinesIN)
        if(line->FromEND==FromEND && line!= this) {
            return false;
        }

    int R = (shape->rect.height()+shape->rect.width())/4;
    double angle = std::atan2(O.y() - From.y(), O.x() - From.x());
    QPoint realEND= QPoint((int)(O.x()-std::cos(angle) * R), (int)(O.y()-std::sin(angle) * R));
    setEnd((const QPoint)realEND);
    return true;
}

void Line::setBegin(const QPoint &beg) {
    From=beg;
}

bool Line::nearEnough(const QPoint &point) {
    double distance= pointToLineDistance(point,From,To);
    return distance<=validDisp;
}

void Line::drawlength(QPainter &painter) {

    // 设置字体

    QFont font;
    font.setFamily("Arial");
    font.setPointSize(16);
    font.setBold(true);
    painter.setFont(font);
    QFontMetrics metrics(painter.font());
    int textHeight = metrics.height();  // 获取文本高度
    // 开启抗锯齿
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    // 设置文本颜色
    painter.setPen(QColor(83,134,139));

    // 绘制文本，居中对齐
    QRect rect((From.x()+To.x())/2-40,(From.y()+To.y())/2-40-textHeight,80,80);
    painter.drawText(rect, Qt::AlignCenter, QString::number(length));

}

void Line::setlength(int len) {
    length=len;
}

int Line::getlength() {
    return length;
}

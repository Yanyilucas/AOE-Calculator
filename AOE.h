//
// Created by LZ on 24-8-21.
//

#ifndef AOE_AOE_H
#define AOE_AOE_H

#include "Line.h"
#include<climits>
class MainWindow;

class AOELine;
class AOENode;
class AOENet;

class AOELine
{
    friend AOENode;
    friend AOENet;
    friend MainWindow;
private:
    //-------数据段---------
    AOENode* From;
    AOENode* To;
    int length;
    //bool isKeyPath= false;
    Line* Frontend_line;////联系前端对象
    //------结构段---------
    AOELine* prev= nullptr;
    AOELine* next= nullptr;
    //------函数段-------
    AOELine(Line* line);
    void insert(AOELine* newline);


};

class AOENode {
    friend AOELine;
    friend AOENet;
    friend MainWindow;
private:
    //------数据段-------
    AOELine* LinesIN= nullptr;//入度
    AOELine* LinesOut= nullptr;//出度
    Shape* Frontend_node;////联系前端对象
public:
    int EST=0; //   最早开始时间
    int LST=INT_MAX;//    最晚开始时间
    int InDegree=0;   //入度.

    //------结构段------
    AOENode* prev= nullptr;
    AOENode* next= nullptr;

    //-----函数段------
    AOENode(Shape* shape);
    void insert(AOENode* newnode);
    //void push_back(AOENode* newnode);
    void addLineIN(AOELine* i_line);
    void addLineOut(AOELine* o_line);
    void removeLineIN(AOELine* i_line);
    //void removeLineOut(AOELine* o_line);

    ~AOENode();
};

class AOENet{
    friend AOENode;
    friend AOELine;
private:
    AOENode* Head= nullptr;


    //-------函数段-------
    static void freeNet(AOENode* Hil);
    void push(AOENode* node,AOENode* &tfinder);
    AOENode* pop(AOENode* node);
public:
    AOENode* Thead= nullptr;
    explicit AOENet(const QList<Shape*>&shapes);
    void removeNode(AOENode* node);
    bool TopologySort();
    void updateEST();
    void updateLST();
    ~AOENet();
};


#endif //AOE_AOE_H

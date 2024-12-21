//
// Created by LZ on 24-8-21.
//

#include "AOE.h"

/****************************AOELine**************************************/
void AOELine::insert(AOELine *newline) {
    if(next== nullptr)
    {
        next=newline;
        newline->prev=this;
        newline->next= nullptr;
    }
    else
    {
        next->prev=newline;
        newline->next=next;
        next=newline;
        newline->prev= this;
    }
}

AOELine::AOELine(Line *line) {
    length=line->getlength();
    line->isKeyPath= false;
    Frontend_line=line;
    From=To= nullptr;
}


/****************************AOENode**************************************/


void AOENode::insert(AOENode *newnode) {
    if(next== nullptr)
    {
        next=newnode;
        newnode->prev=this;
        newnode->next= nullptr;
    }
    else
    {
        next->prev=newnode;
        newnode->next=next;
        next=newnode;
        newnode->prev= this;
    }
}

void AOENode::addLineIN(AOELine *i_line) {
    AOELine* finder=LinesIN;
    if(finder== nullptr)
        LinesIN=i_line;
    else
    {
        for(finder=LinesIN;finder->next!= nullptr;finder=finder->next);
        finder->insert(i_line);
    }
    InDegree++;
}

void AOENode::addLineOut(AOELine *o_line) {
    AOELine* finder=LinesOut;
    if(finder== nullptr)
        LinesOut=o_line;
    else
    {
        for(finder=LinesOut;finder->next!= nullptr;finder=finder->next);
        finder->insert(o_line);
    }
}

AOENode::~AOENode() {
    // 释放入度链表的内存
    AOELine* current = LinesIN;
    while (current != nullptr) {
        AOELine* nextline = current->next;
        delete current;
        current = nextline;
    }

    // 释放出度链表的内存
    current = LinesOut;
    while (current != nullptr) {
        AOELine* nextline = current->next;
        delete current;
        current = nextline;
    }
}

void AOENode::removeLineIN(AOELine *i_line) {
    if(LinesIN)
    {
        AOELine* finder=LinesIN;
        for(;finder;) {
            if (finder->Frontend_line == i_line->Frontend_line) {
                if (finder->prev == nullptr) {
                    LinesIN = finder->next;
                    if (LinesIN)LinesIN->prev = nullptr;
                } else {
                    finder->prev->next = finder->next;
                    if (finder->next)finder->next->prev = finder->prev;
                }
                AOELine *tmp = finder;
                finder = finder->next;//如果是动态内存申请的
                delete tmp;
                InDegree--;
            }
            else
            finder = finder->next;//如果是动态内存申请的
        }
    }
}
/*
void AOENode::removeLineOut(AOELine *o_line) {
    if(LinesOut)
    {
        AOELine* finder=LinesOut;
        for(;finder;)
            if(finder->Frontend_line==o_line->Frontend_line) {
                if (finder->prev == nullptr){
                    LinesOut=finder->next;
                    if(LinesOut)LinesOut->prev= nullptr;
                }
                else{
                    finder->prev->next=finder->next;
                    if(finder->next)finder->next->prev=finder->prev;
                }
                //AOELine* tmp=finder;
                finder=finder->next;//如果是动态内存申请的
                //delete tmp;
            }
    }
}
*/
/*
void AOENode::push_back(AOENode* node) {
    AOENode* finder= this;
    for(;finder->next;finder=finder->next);
    finder->insert(node);
}
*/
AOENode::AOENode(Shape* shape) {
    Frontend_node=shape;
    shape->TOPONum=0;
    for(Line* & line:shape->LinesIN)
        addLineIN(new AOELine(line));
    for(Line* & line:shape->LinesOut)
        addLineOut(new AOELine(line));
}

/****************************AOENet**************************************/
bool AOENet::TopologySort() {
    //从Head开始,构建一个全新的AOENode Queue
   AOENode* t=Thead;
   AOENode* finder=Head;
   int N=1;
    while(true)
    {
        AOENode* tmp=pop(finder);
        if(tmp!= nullptr)
        {
            push(tmp,t);
            tmp->Frontend_node->TOPONum=N;
            N++;
            removeNode(tmp);
        } else break;
        finder=finder->next;
        if(finder== nullptr)finder=Head;
    }

    return Head== nullptr;
}

void AOENet::freeNet(AOENode *Hil) {
    if(Hil)
    {
        AOENode* finder=Hil;
        while (finder!= nullptr)
        {
            AOENode* current=finder;
            finder=finder->next;
            delete current;
        }
    }
}

void AOENet::push(AOENode *node, AOENode *&tfinder) {
    //在ptr的后方插入node.
    if(Thead== nullptr)
    {
        Thead=node;
        Thead->prev= nullptr;
        Thead->next= nullptr;
        tfinder=Thead;
    }
    else
    {
        (tfinder)->insert(node);
        (tfinder)=(tfinder)->next;
    }
}

AOENode *AOENet::pop(AOENode* begin) {
    if(Head== nullptr)return nullptr;
    AOENode *finder=Head;
    if(begin!= nullptr)
        finder=begin;
    AOENode *tmp= nullptr;

    while(true) {
        if (finder->InDegree == 0) {
            tmp = finder;
            break;
        }
        finder=finder->next;
        if(finder==nullptr)finder=Head;
        if(finder==begin)return nullptr;
    }

    if(tmp== nullptr)return nullptr;

    if(finder==Head)
    {
        Head=finder->next;
        if(Head!= nullptr) Head->prev= nullptr;
        finder->next= nullptr;
    }
    else
    {
        finder->prev->next=finder->next;
        if(finder->next!= nullptr)
            finder->next->prev=finder->prev;
        finder->prev= nullptr;
    }
    return tmp;
}

void AOENet::removeNode(AOENode *node) {
    //移除node后,删除连线
    AOENode* finder=Head;
    if(Head== nullptr)return;
    while (finder)
    {
        //AOELine* In=node->LinesIN;
        AOELine* Out=node->LinesOut;
        /*出边不用删除,总边数存了两倍,仅删除一半,拓扑排序节点恰好为所有边
        for(AOELine* p=In;p!= nullptr;)
        {
            p->From->removeLineOut(p);
            AOELine*tmp=p;
            p=p->next;
            delete tmp;
        }
        */
        for(AOELine* p=Out;p!= nullptr;)
        {
            p->To->removeLineIN(p);
            //AOELine*tmp=p;
            p=p->next;
            //delete tmp;
        }
        finder=finder->next;
    }

}

AOENet::AOENet(const QList<Shape *>& shapes) {
    AOENode* finder=Head;
    //创建节点链表及其出入边分支.
    for(Shape *shape:shapes)
    {
        if(finder== nullptr)
            finder=Head=new AOENode(shape);
        else
        {
            finder->insert(new AOENode(shape));
            finder=finder->next;
        }
    }

    //对所有节点的出边,找到它的终点.
    for(AOENode* finder1=Head;finder1;finder1=finder1->next)
    {
        AOELine*Out=finder1->LinesOut;
        for(AOELine* ot=Out;ot;ot=ot->next)
            for(AOENode* finder2=Head;finder2;finder2=finder2->next)
            {
                if(ot->To!= nullptr)break;
                AOELine* IN=finder2->LinesIN;
                for(AOELine* it=IN;it;it=it->next)
                    if(it->Frontend_line==ot->Frontend_line)
                        ot->To=finder2;
            }

    }
    //对所有节点的入边,找到它的起点.
    for(AOENode* finder1=Head;finder1;finder1=finder1->next)
    {
        AOELine*In=finder1->LinesIN;
        for(AOELine* it=In;it;it=it->next)
            for(AOENode* finder2=Head;finder2;finder2=finder2->next)
            {
                if(it->From!= nullptr)break;
                AOELine* Out=finder2->LinesOut;
                for(AOELine* ot=Out;ot;ot=ot->next)
                    if(it->Frontend_line==ot->Frontend_line)
                        it->From=finder2;
            }

    }
}

AOENet::~AOENet() {
    //分成两个部分:拓扑排序的Thead.环形的Head
    for (AOENode* finder=Thead;finder!= nullptr;) {
        AOENode* tmp=finder;
        finder=finder->next;
        delete tmp;
    }

    for (AOENode* finder=Head;finder!= nullptr;) {
        AOENode* tmp=finder;
        finder=finder->next;
        delete tmp;
    }
}

void AOENet::updateEST() {
    //从Thead开始
    if(Thead== nullptr)return;
    AOENode* finder=Thead;
    while (finder)
    {

        for(AOELine* o_line=finder->LinesOut;o_line;o_line=o_line->next)
        {
            if(o_line->To->EST<finder->EST+o_line->length)
                o_line->To->EST=finder->EST+o_line->length;
        }

        /*
        for(AOENode* node=Thead;node;node=node->next)
        {
            for(AOELine* o_line=node->LinesOut;o_line;o_line=o_line->next)
                if(o_line->To==finder)
                    if(finder->EST<node->EST+o_line->length)
                    {
                        finder->EST=node->EST+o_line->length;
                        break;
                    }

        }
        */
        finder=finder->next;
    }

}

void AOENet::updateLST() {
    //从末尾开始
    if(Thead== nullptr)return;
    AOENode* finder=Thead;
    int lst=-1;//找到最晚开始的活动
    for(AOENode* fN=Thead;fN;fN=fN->next)//将LST初始化为EST
        lst=fN->EST>lst?fN->EST:lst;

    for(;finder->next;finder=finder->next)//将LST初始化为EST
        finder->LST=lst;

    finder->LST=lst;
    while (finder)
    {
        for(AOELine* o_line=finder->LinesOut;o_line;o_line=o_line->next)
        {
            if(finder->LST>o_line->To->LST-o_line->length)
                finder->LST=o_line->To->LST-o_line->length;
        }
        finder=finder->prev;
    }
}



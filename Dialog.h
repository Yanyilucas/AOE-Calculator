//
// Created by LZ on 24-8-21.
//

#ifndef AOE_DIALOG_H
#define AOE_DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QPushButton>
#include <QMessageBox>
#include <QAction>
#include "Line.h"

class Dialog: public QDialog{
Q_OBJECT
public:
    Dialog(Line* currLine,QWidget* parent = nullptr);

};


#endif //AOE_DIALOG_H

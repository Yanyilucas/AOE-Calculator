/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcanvas.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_save;
    QAction *action_run_project;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QCanvas *Canvas;
    QStatusBar *statusbar;
    QDockWidget *Dock;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_showtime;
    QLabel *label_3;
    QLCDNumber *lcdNumber;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *tabNode;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tabLine;
    QFrame *line;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(1600, 900));
        action_save = new QAction(MainWindow);
        action_save->setObjectName("action_save");
        action_run_project = new QAction(MainWindow);
        action_run_project->setObjectName("action_run_project");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setObjectName("verticalLayout_6");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 473, 523));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName("gridLayout");
        Canvas = new QCanvas(scrollAreaWidgetContents);
        Canvas->setObjectName("Canvas");
        QFont font;
        font.setBold(false);
        Canvas->setFont(font);
        Canvas->setMouseTracking(true);

        gridLayout->addWidget(Canvas, 0, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_6->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        Dock = new QDockWidget(MainWindow);
        Dock->setObjectName("Dock");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(255);
        sizePolicy.setVerticalStretch(255);
        sizePolicy.setHeightForWidth(Dock->sizePolicy().hasHeightForWidth());
        Dock->setSizePolicy(sizePolicy);
        Dock->setMinimumSize(QSize(252, 600));
        Dock->setMaximumSize(QSize(300, 900));
        Dock->setFloating(false);
        Dock->setFeatures(QDockWidget::DockWidgetFeature::DockWidgetFloatable);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName("dockWidgetContents_4");
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        tabWidget_2 = new QTabWidget(dockWidgetContents_4);
        tabWidget_2->setObjectName("tabWidget_2");
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(tab_3);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        checkBox = new QCheckBox(tab_3);
        checkBox->setObjectName("checkBox");
        checkBox->setEnabled(false);

        horizontalLayout_2->addWidget(checkBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_showtime = new QLabel(tab_3);
        label_showtime->setObjectName("label_showtime");

        horizontalLayout_3->addWidget(label_showtime);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        lcdNumber = new QLCDNumber(tab_3);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        lcdNumber->setFrameShadow(QFrame::Shadow::Sunken);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setProperty("intValue", QVariant(0));

        horizontalLayout_3->addWidget(lcdNumber);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        line_2 = new QFrame(tab_3);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_4->addWidget(line_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_4 = new QLabel(tab_3);
        label_4->setObjectName("label_4");

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(tab_3);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);


        horizontalLayout_4->addLayout(verticalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_4);

        tabNode = new QTableWidget(tab_3);
        if (tabNode->columnCount() < 3)
            tabNode->setColumnCount(3);
        QFont font1;
        font1.setPointSize(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tabNode->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tabNode->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tabNode->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tabNode->setObjectName("tabNode");
        tabNode->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        tabNode->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        tabNode->horizontalHeader()->setVisible(true);
        tabNode->horizontalHeader()->setCascadingSectionResizes(false);
        tabNode->horizontalHeader()->setDefaultSectionSize(75);
        tabNode->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tabNode->horizontalHeader()->setStretchLastSection(true);
        tabNode->verticalHeader()->setVisible(false);

        verticalLayout_4->addWidget(tabNode);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        horizontalLayout = new QHBoxLayout(tab_4);
        horizontalLayout->setObjectName("horizontalLayout");
        tabLine = new QTableWidget(tab_4);
        if (tabLine->columnCount() < 4)
            tabLine->setColumnCount(4);
        QFont font2;
        font2.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        tabLine->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font2);
        tabLine->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font2);
        tabLine->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font2);
        tabLine->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        tabLine->setObjectName("tabLine");
        tabLine->horizontalHeader()->setDefaultSectionSize(55);
        tabLine->horizontalHeader()->setStretchLastSection(true);
        tabLine->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(tabLine);

        tabWidget_2->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget_2);


        verticalLayout_2->addLayout(verticalLayout);

        line = new QFrame(dockWidgetContents_4);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_2->addWidget(line);

        Dock->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, Dock);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(action_save);
        menu_3->addAction(action_run_project);

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "AOE", nullptr));
        action_save->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(shortcut)
        action_save->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_run_project->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\345\267\245\347\250\213", nullptr));
#if QT_CONFIG(shortcut)
        action_run_project->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("MainWindow", "\345\267\245\347\250\213\346\230\257\345\220\246\345\217\257\350\241\214", nullptr));
        checkBox->setText(QString());
        label_showtime->setText(QCoreApplication::translate("MainWindow", "\346\234\200\346\227\251\345\256\214\346\210\220\346\227\266\351\227\264", nullptr));
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "EST:\344\272\213\344\273\266\346\234\200\346\227\251\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "LST:\344\272\213\344\273\266\346\234\200\350\277\237\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tabNode->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tabNode->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "EST", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tabNode->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "LST", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\344\272\213\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tabLine->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\350\265\267\347\202\271\344\272\213\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tabLine->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\347\273\210\347\202\271\344\272\213\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tabLine->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\346\227\266\345\267\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tabLine->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\224\256\346\264\273\345\212\250", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\346\264\273\345\212\250", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\350\277\220\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

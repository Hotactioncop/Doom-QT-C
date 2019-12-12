/********************************************************************************
** Form generated from reading UI file 'doom.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOOM_H
#define UI_DOOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "gamezone.h"

QT_BEGIN_NAMESPACE

class Ui_Doom
{
public:
    QAction *actionStart;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    GameZone *GameWidget;
    QMenuBar *menuBar;
    QMenu *menuStart;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Doom)
    {
        if (Doom->objectName().isEmpty())
            Doom->setObjectName(QString::fromUtf8("Doom"));
        Doom->resize(839, 652);
        actionStart = new QAction(Doom);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        centralWidget = new QWidget(Doom);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        GameWidget = new GameZone(centralWidget);
        GameWidget->setObjectName(QString::fromUtf8("GameWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameWidget->sizePolicy().hasHeightForWidth());
        GameWidget->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(GameWidget);


        horizontalLayout->addLayout(verticalLayout);

        Doom->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Doom);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 839, 21));
        menuStart = new QMenu(menuBar);
        menuStart->setObjectName(QString::fromUtf8("menuStart"));
        Doom->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Doom);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Doom->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Doom);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Doom->setStatusBar(statusBar);

        menuBar->addAction(menuStart->menuAction());
        menuStart->addAction(actionStart);
        mainToolBar->addAction(actionStart);

        retranslateUi(Doom);
        QObject::connect(actionStart, SIGNAL(triggered()), GameWidget, SLOT(StartGame()));

        QMetaObject::connectSlotsByName(Doom);
    } // setupUi

    void retranslateUi(QMainWindow *Doom)
    {
        Doom->setWindowTitle(QApplication::translate("Doom", "Doom", nullptr));
        actionStart->setText(QApplication::translate("Doom", "Start", nullptr));
        menuStart->setTitle(QApplication::translate("Doom", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Doom: public Ui_Doom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOOM_H

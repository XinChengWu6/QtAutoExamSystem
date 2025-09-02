/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionAddSingleChoice;
    QAction *actionAddMultipleChoice;
    QAction *actionAddJudgement;
    QAction *actionAddEssay;
    QAction *actionStarExam;
    QWidget *centralwidget;
    QTableWidget *questionTable;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuquestion;
    QMenu *menuExam;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(702, 492);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAddSingleChoice = new QAction(MainWindow);
        actionAddSingleChoice->setObjectName("actionAddSingleChoice");
        actionAddMultipleChoice = new QAction(MainWindow);
        actionAddMultipleChoice->setObjectName("actionAddMultipleChoice");
        actionAddJudgement = new QAction(MainWindow);
        actionAddJudgement->setObjectName("actionAddJudgement");
        actionAddEssay = new QAction(MainWindow);
        actionAddEssay->setObjectName("actionAddEssay");
        actionStarExam = new QAction(MainWindow);
        actionStarExam->setObjectName("actionStarExam");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        questionTable = new QTableWidget(centralwidget);
        questionTable->setObjectName("questionTable");
        questionTable->setGeometry(QRect(120, 50, 441, 281));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 702, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuquestion = new QMenu(menubar);
        menuquestion->setObjectName("menuquestion");
        menuExam = new QMenu(menubar);
        menuExam->setObjectName("menuExam");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuquestion->menuAction());
        menubar->addAction(menuExam->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuquestion->addAction(actionAddSingleChoice);
        menuquestion->addAction(actionAddMultipleChoice);
        menuquestion->addAction(actionAddJudgement);
        menuquestion->addAction(actionAddEssay);
        menuExam->addAction(actionStarExam);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\350\257\225\345\215\267", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\350\257\225\345\215\267", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\350\257\225\345\215\267", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actionAddSingleChoice->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\215\225\351\200\211\351\242\230", nullptr));
        actionAddMultipleChoice->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\244\232\351\200\211\351\242\230", nullptr));
        actionAddJudgement->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\210\244\346\226\255\351\242\230", nullptr));
        actionAddEssay->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\351\227\256\347\255\224\351\242\230", nullptr));
        actionStarExam->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\200\203\350\257\225", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuquestion->setTitle(QCoreApplication::translate("MainWindow", "\345\207\272\351\242\230", nullptr));
        menuExam->setTitle(QCoreApplication::translate("MainWindow", "\350\200\203\350\257\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

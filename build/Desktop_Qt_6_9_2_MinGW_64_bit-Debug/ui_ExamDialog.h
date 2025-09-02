/********************************************************************************
** Form generated from reading UI file 'ExamDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMDIALOG_H
#define UI_EXAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *questionLabel;
    QListWidget *answerWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *prevButton;
    QPushButton *nextButton;
    QPushButton *submitButton;

    void setupUi(QDialog *ExamDialog)
    {
        if (ExamDialog->objectName().isEmpty())
            ExamDialog->setObjectName("ExamDialog");
        ExamDialog->resize(955, 631);
        layoutWidget = new QWidget(ExamDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(220, 50, 328, 252));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        questionLabel = new QLabel(layoutWidget);
        questionLabel->setObjectName("questionLabel");

        horizontalLayout->addWidget(questionLabel);

        answerWidget = new QListWidget(layoutWidget);
        answerWidget->setObjectName("answerWidget");

        horizontalLayout->addWidget(answerWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        horizontalLayout->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        prevButton = new QPushButton(layoutWidget);
        prevButton->setObjectName("prevButton");

        verticalLayout->addWidget(prevButton);

        nextButton = new QPushButton(layoutWidget);
        nextButton->setObjectName("nextButton");

        verticalLayout->addWidget(nextButton);

        submitButton = new QPushButton(layoutWidget);
        submitButton->setObjectName("submitButton");

        verticalLayout->addWidget(submitButton);


        retranslateUi(ExamDialog);

        nextButton->setDefault(true);


        QMetaObject::connectSlotsByName(ExamDialog);
    } // setupUi

    void retranslateUi(QDialog *ExamDialog)
    {
        ExamDialog->setWindowTitle(QCoreApplication::translate("ExamDialog", "Dialog", nullptr));
        questionLabel->setText(QCoreApplication::translate("ExamDialog", " \351\242\230\347\233\256\345\206\205\345\256\271\357\274\232", nullptr));
        prevButton->setText(QCoreApplication::translate("ExamDialog", "\344\270\212\344\270\200\351\242\230", nullptr));
        nextButton->setText(QCoreApplication::translate("ExamDialog", "\344\270\213\344\270\200\351\242\230", nullptr));
        submitButton->setText(QCoreApplication::translate("ExamDialog", "\346\217\220\344\272\244\350\257\225\345\215\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamDialog: public Ui_ExamDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'EssayDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESSAYDIALOG_H
#define UI_ESSAYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EssayDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *descriptionEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *scoreSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *keywordsEdit;
    QGroupBox *ruleGroup;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *containsAnyRadio;
    QRadioButton *containsAllRadio;
    QRadioButton *coutKeywordsRadio;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *EssayDialog)
    {
        if (EssayDialog->objectName().isEmpty())
            EssayDialog->setObjectName("EssayDialog");
        EssayDialog->resize(586, 473);
        layoutWidget = new QWidget(EssayDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(90, 30, 221, 231));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        descriptionEdit = new QLineEdit(layoutWidget);
        descriptionEdit->setObjectName("descriptionEdit");

        horizontalLayout->addWidget(descriptionEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        scoreSpinBox = new QSpinBox(layoutWidget);
        scoreSpinBox->setObjectName("scoreSpinBox");
        scoreSpinBox->setMinimum(1);
        scoreSpinBox->setMaximum(100);
        scoreSpinBox->setValue(10);

        horizontalLayout_2->addWidget(scoreSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        keywordsEdit = new QLineEdit(layoutWidget);
        keywordsEdit->setObjectName("keywordsEdit");

        horizontalLayout_3->addWidget(keywordsEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_2);

        ruleGroup = new QGroupBox(layoutWidget);
        ruleGroup->setObjectName("ruleGroup");
        verticalLayout_3 = new QVBoxLayout(ruleGroup);
        verticalLayout_3->setObjectName("verticalLayout_3");
        containsAnyRadio = new QRadioButton(ruleGroup);
        containsAnyRadio->setObjectName("containsAnyRadio");

        verticalLayout_3->addWidget(containsAnyRadio);

        containsAllRadio = new QRadioButton(ruleGroup);
        containsAllRadio->setObjectName("containsAllRadio");

        verticalLayout_3->addWidget(containsAllRadio);

        coutKeywordsRadio = new QRadioButton(ruleGroup);
        coutKeywordsRadio->setObjectName("coutKeywordsRadio");

        verticalLayout_3->addWidget(coutKeywordsRadio);


        verticalLayout_4->addWidget(ruleGroup);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName("okButton");

        horizontalLayout_4->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_4->addWidget(cancelButton);


        verticalLayout_5->addLayout(horizontalLayout_4);


        retranslateUi(EssayDialog);
        QObject::connect(okButton, &QPushButton::clicked, EssayDialog, qOverload<>(&QDialog::accept));
        QObject::connect(cancelButton, &QPushButton::clicked, EssayDialog, qOverload<>(&QDialog::reject));

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(EssayDialog);
    } // setupUi

    void retranslateUi(QDialog *EssayDialog)
    {
        EssayDialog->setWindowTitle(QCoreApplication::translate("EssayDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EssayDialog", "\351\242\230\345\271\262\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("EssayDialog", "\345\210\206\345\200\274", nullptr));
        label_3->setText(QCoreApplication::translate("EssayDialog", "\345\205\263\351\224\256\350\257\215\357\274\232", nullptr));
        ruleGroup->setTitle(QCoreApplication::translate("EssayDialog", "\350\257\204\345\210\206\350\247\204\345\210\231", nullptr));
        containsAnyRadio->setText(QCoreApplication::translate("EssayDialog", "\345\214\205\345\220\253\344\273\273\346\204\217\345\205\263\351\224\256\350\257\215\345\215\263\345\276\227\345\210\206", nullptr));
        containsAllRadio->setText(QCoreApplication::translate("EssayDialog", "\345\214\205\345\220\253\346\211\200\346\234\211\345\205\263\351\224\256\350\257\215\345\276\227\345\210\206", nullptr));
        coutKeywordsRadio->setText(QCoreApplication::translate("EssayDialog", "\346\240\271\346\215\256\345\214\205\345\220\253\345\205\263\351\224\256\350\257\215\347\232\204\346\225\260\351\207\217\346\214\211\346\257\224\344\276\213\345\276\227\345\210\206", nullptr));
        okButton->setText(QCoreApplication::translate("EssayDialog", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("EssayDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EssayDialog: public Ui_EssayDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESSAYDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'JudgementDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JUDGEMENTDIALOG_H
#define UI_JUDGEMENTDIALOG_H

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

class Ui_JudgementDialog
{
public:
    QGroupBox *answerGroup;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *trueButton;
    QRadioButton *falseButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *descriptionEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *scoreSpinBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *JudgementDialog)
    {
        if (JudgementDialog->objectName().isEmpty())
            JudgementDialog->setObjectName("JudgementDialog");
        JudgementDialog->resize(400, 300);
        answerGroup = new QGroupBox(JudgementDialog);
        answerGroup->setObjectName("answerGroup");
        answerGroup->setGeometry(QRect(60, 90, 191, 80));
        layoutWidget = new QWidget(answerGroup);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 30, 100, 21));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        trueButton = new QRadioButton(layoutWidget);
        trueButton->setObjectName("trueButton");

        horizontalLayout_4->addWidget(trueButton);

        falseButton = new QRadioButton(layoutWidget);
        falseButton->setObjectName("falseButton");

        horizontalLayout_4->addWidget(falseButton);

        layoutWidget1 = new QWidget(JudgementDialog);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(60, 20, 181, 52));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        descriptionEdit = new QLineEdit(layoutWidget1);
        descriptionEdit->setObjectName("descriptionEdit");

        horizontalLayout->addWidget(descriptionEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        scoreSpinBox = new QSpinBox(layoutWidget1);
        scoreSpinBox->setObjectName("scoreSpinBox");
        scoreSpinBox->setMinimum(1);
        scoreSpinBox->setMaximum(100);
        scoreSpinBox->setValue(10);

        horizontalLayout_2->addWidget(scoreSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget2 = new QWidget(JudgementDialog);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(60, 190, 156, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(layoutWidget2);
        okButton->setObjectName("okButton");

        horizontalLayout_3->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget2);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_3->addWidget(cancelButton);


        retranslateUi(JudgementDialog);
        QObject::connect(okButton, &QPushButton::clicked, JudgementDialog, qOverload<>(&QDialog::accept));
        QObject::connect(cancelButton, &QPushButton::clicked, JudgementDialog, qOverload<>(&QDialog::reject));

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(JudgementDialog);
    } // setupUi

    void retranslateUi(QDialog *JudgementDialog)
    {
        JudgementDialog->setWindowTitle(QCoreApplication::translate("JudgementDialog", "Dialog", nullptr));
        answerGroup->setTitle(QCoreApplication::translate("JudgementDialog", "\346\255\243\347\241\256\347\255\224\346\241\210", nullptr));
        trueButton->setText(QCoreApplication::translate("JudgementDialog", "\346\255\243\347\241\256", nullptr));
        falseButton->setText(QCoreApplication::translate("JudgementDialog", "\351\224\231\350\257\257", nullptr));
        label->setText(QCoreApplication::translate("JudgementDialog", "\351\242\230\345\271\262\357\274\232 ", nullptr));
        label_2->setText(QCoreApplication::translate("JudgementDialog", "\345\210\206\345\200\274", nullptr));
        okButton->setText(QCoreApplication::translate("JudgementDialog", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("JudgementDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JudgementDialog: public Ui_JudgementDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUDGEMENTDIALOG_H

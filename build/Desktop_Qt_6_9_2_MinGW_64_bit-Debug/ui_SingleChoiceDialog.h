/********************************************************************************
** Form generated from reading UI file 'SingleChoiceDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLECHOICEDIALOG_H
#define UI_SINGLECHOICEDIALOG_H

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

class Ui_SingleChoiceDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QSpinBox *scoreSpinBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *descriptionEdit;
    QGroupBox *optionsGroup;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *option1Radio;
    QLineEdit *option1edit;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *option2Radio;
    QLineEdit *optin2Edit;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *option3Radio;
    QLineEdit *option3Edit;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *option4Radio;
    QLineEdit *option4Edit;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *removeOptionButton;
    QPushButton *addoptionButton;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *SingleChoiceDialog)
    {
        if (SingleChoiceDialog->objectName().isEmpty())
            SingleChoiceDialog->setObjectName("SingleChoiceDialog");
        SingleChoiceDialog->resize(500, 400);
        layoutWidget = new QWidget(SingleChoiceDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(120, 20, 252, 234));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_7->addWidget(label_2);

        scoreSpinBox = new QSpinBox(layoutWidget);
        scoreSpinBox->setObjectName("scoreSpinBox");
        scoreSpinBox->setMinimum(1);
        scoreSpinBox->setMaximum(100);
        scoreSpinBox->setValue(10);

        horizontalLayout_7->addWidget(scoreSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout_6->addWidget(label);

        descriptionEdit = new QLineEdit(layoutWidget);
        descriptionEdit->setObjectName("descriptionEdit");

        horizontalLayout_6->addWidget(descriptionEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);

        optionsGroup = new QGroupBox(layoutWidget);
        optionsGroup->setObjectName("optionsGroup");
        verticalLayout = new QVBoxLayout(optionsGroup);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        option1Radio = new QRadioButton(optionsGroup);
        option1Radio->setObjectName("option1Radio");
        option1Radio->setChecked(true);

        horizontalLayout->addWidget(option1Radio);

        option1edit = new QLineEdit(optionsGroup);
        option1edit->setObjectName("option1edit");

        horizontalLayout->addWidget(option1edit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        option2Radio = new QRadioButton(optionsGroup);
        option2Radio->setObjectName("option2Radio");

        horizontalLayout_2->addWidget(option2Radio);

        optin2Edit = new QLineEdit(optionsGroup);
        optin2Edit->setObjectName("optin2Edit");

        horizontalLayout_2->addWidget(optin2Edit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        option3Radio = new QRadioButton(optionsGroup);
        option3Radio->setObjectName("option3Radio");

        horizontalLayout_3->addWidget(option3Radio);

        option3Edit = new QLineEdit(optionsGroup);
        option3Edit->setObjectName("option3Edit");

        horizontalLayout_3->addWidget(option3Edit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        option4Radio = new QRadioButton(optionsGroup);
        option4Radio->setObjectName("option4Radio");

        horizontalLayout_4->addWidget(option4Radio);

        option4Edit = new QLineEdit(optionsGroup);
        option4Edit->setObjectName("option4Edit");

        horizontalLayout_4->addWidget(option4Edit);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(optionsGroup);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        removeOptionButton = new QPushButton(layoutWidget);
        removeOptionButton->setObjectName("removeOptionButton");

        horizontalLayout_5->addWidget(removeOptionButton);

        addoptionButton = new QPushButton(layoutWidget);
        addoptionButton->setObjectName("addoptionButton");

        horizontalLayout_5->addWidget(addoptionButton);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout_8->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_8->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout_8);


        retranslateUi(SingleChoiceDialog);
        QObject::connect(pushButton_2, &QPushButton::clicked, SingleChoiceDialog, qOverload<>(&QDialog::reject));
        QObject::connect(pushButton, &QPushButton::clicked, SingleChoiceDialog, qOverload<>(&QDialog::accept));

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(SingleChoiceDialog);
    } // setupUi

    void retranslateUi(QDialog *SingleChoiceDialog)
    {
        SingleChoiceDialog->setWindowTitle(QCoreApplication::translate("SingleChoiceDialog", "\345\215\225\351\200\211\351\242\230\347\274\226\350\276\221", nullptr));
        label_2->setText(QCoreApplication::translate("SingleChoiceDialog", "\345\210\206\345\200\274\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("SingleChoiceDialog", "\351\242\230\345\271\262\357\274\232", nullptr));
        optionsGroup->setTitle(QString());
        option1Radio->setText(QString());
        option1edit->setPlaceholderText(QCoreApplication::translate("SingleChoiceDialog", "\351\200\211\351\241\2711", nullptr));
        option2Radio->setText(QString());
        optin2Edit->setText(QString());
        optin2Edit->setPlaceholderText(QCoreApplication::translate("SingleChoiceDialog", "\351\200\211\351\241\2712", nullptr));
        option3Radio->setText(QString());
        option3Edit->setText(QString());
        option3Edit->setPlaceholderText(QCoreApplication::translate("SingleChoiceDialog", "\351\200\211\351\241\2713", nullptr));
        option4Radio->setText(QString());
        option4Edit->setText(QString());
        option4Edit->setPlaceholderText(QCoreApplication::translate("SingleChoiceDialog", "\351\200\211\351\241\2714", nullptr));
        removeOptionButton->setText(QCoreApplication::translate("SingleChoiceDialog", "\345\210\240\351\231\244\351\200\211\351\241\271", nullptr));
        addoptionButton->setText(QCoreApplication::translate("SingleChoiceDialog", "\346\267\273\345\212\240\351\200\211\351\241\271", nullptr));
        pushButton->setText(QCoreApplication::translate("SingleChoiceDialog", " \347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SingleChoiceDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SingleChoiceDialog: public Ui_SingleChoiceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLECHOICEDIALOG_H

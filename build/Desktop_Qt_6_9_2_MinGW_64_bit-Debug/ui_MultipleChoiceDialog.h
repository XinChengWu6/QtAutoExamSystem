/********************************************************************************
** Form generated from reading UI file 'MultipleChoiceDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLECHOICEDIALOG_H
#define UI_MULTIPLECHOICEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultipleChoiceDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *descriptionEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpinBox *scoreSpinBox;
    QGroupBox *optionsGroup;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *option1Check;
    QLineEdit *option1Edit;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *option2Check;
    QLineEdit *option2Edit;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *option3Check;
    QLineEdit *option3Edit;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *option4Check;
    QLineEdit *option4Edit;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *addOptionButtion;
    QPushButton *removeOptionButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *MultipleChoiceDialog)
    {
        if (MultipleChoiceDialog->objectName().isEmpty())
            MultipleChoiceDialog->setObjectName("MultipleChoiceDialog");
        MultipleChoiceDialog->resize(729, 509);
        layoutWidget = new QWidget(MultipleChoiceDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(120, 60, 234, 251));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        descriptionEdit = new QLineEdit(layoutWidget);
        descriptionEdit->setObjectName("descriptionEdit");

        horizontalLayout_3->addWidget(descriptionEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_4->addWidget(label_2);

        scoreSpinBox = new QSpinBox(layoutWidget);
        scoreSpinBox->setObjectName("scoreSpinBox");
        scoreSpinBox->setMinimum(1);
        scoreSpinBox->setMaximum(100);
        scoreSpinBox->setValue(10);

        horizontalLayout_4->addWidget(scoreSpinBox);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout);

        optionsGroup = new QGroupBox(layoutWidget);
        optionsGroup->setObjectName("optionsGroup");
        verticalLayout_3 = new QVBoxLayout(optionsGroup);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        option1Check = new QCheckBox(optionsGroup);
        option1Check->setObjectName("option1Check");

        horizontalLayout_5->addWidget(option1Check);

        option1Edit = new QLineEdit(optionsGroup);
        option1Edit->setObjectName("option1Edit");

        horizontalLayout_5->addWidget(option1Edit);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        option2Check = new QCheckBox(optionsGroup);
        option2Check->setObjectName("option2Check");

        horizontalLayout_6->addWidget(option2Check);

        option2Edit = new QLineEdit(optionsGroup);
        option2Edit->setObjectName("option2Edit");

        horizontalLayout_6->addWidget(option2Edit);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        option3Check = new QCheckBox(optionsGroup);
        option3Check->setObjectName("option3Check");

        horizontalLayout_7->addWidget(option3Check);

        option3Edit = new QLineEdit(optionsGroup);
        option3Edit->setObjectName("option3Edit");

        horizontalLayout_7->addWidget(option3Edit);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        option4Check = new QCheckBox(optionsGroup);
        option4Check->setObjectName("option4Check");

        horizontalLayout_8->addWidget(option4Check);

        option4Edit = new QLineEdit(optionsGroup);
        option4Edit->setObjectName("option4Edit");

        horizontalLayout_8->addWidget(option4Edit);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout_4->addWidget(optionsGroup);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addOptionButtion = new QPushButton(layoutWidget);
        addOptionButtion->setObjectName("addOptionButtion");

        horizontalLayout->addWidget(addOptionButtion);

        removeOptionButton = new QPushButton(layoutWidget);
        removeOptionButton->setObjectName("removeOptionButton");

        horizontalLayout->addWidget(removeOptionButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName("okButton");

        horizontalLayout_2->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);


        retranslateUi(MultipleChoiceDialog);
        QObject::connect(okButton, &QPushButton::clicked, MultipleChoiceDialog, qOverload<>(&QDialog::accept));
        QObject::connect(cancelButton, &QPushButton::clicked, MultipleChoiceDialog, qOverload<>(&QDialog::reject));

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(MultipleChoiceDialog);
    } // setupUi

    void retranslateUi(QDialog *MultipleChoiceDialog)
    {
        MultipleChoiceDialog->setWindowTitle(QCoreApplication::translate("MultipleChoiceDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MultipleChoiceDialog", "\351\242\230\345\271\262\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MultipleChoiceDialog", "\345\210\206\345\200\274\357\274\232", nullptr));
        optionsGroup->setTitle(QCoreApplication::translate("MultipleChoiceDialog", "\351\200\211\351\241\271", nullptr));
        option1Check->setText(QString());
        option1Edit->setPlaceholderText(QCoreApplication::translate("MultipleChoiceDialog", "\351\200\211\351\241\2711", nullptr));
        option2Check->setText(QString());
        option2Edit->setPlaceholderText(QCoreApplication::translate("MultipleChoiceDialog", "\351\200\211\351\241\2712", nullptr));
        option3Check->setText(QString());
        option3Edit->setPlaceholderText(QCoreApplication::translate("MultipleChoiceDialog", "\351\200\211\351\241\2713", nullptr));
        option4Check->setText(QString());
        option4Edit->setPlaceholderText(QCoreApplication::translate("MultipleChoiceDialog", "\351\200\211\351\241\2714", nullptr));
        addOptionButtion->setText(QCoreApplication::translate("MultipleChoiceDialog", "\346\267\273\345\212\240\351\200\211\351\241\271", nullptr));
        removeOptionButton->setText(QCoreApplication::translate("MultipleChoiceDialog", "\345\210\240\351\231\244\351\200\211\351\241\271", nullptr));
        okButton->setText(QCoreApplication::translate("MultipleChoiceDialog", " \347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("MultipleChoiceDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MultipleChoiceDialog: public Ui_MultipleChoiceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLECHOICEDIALOG_H

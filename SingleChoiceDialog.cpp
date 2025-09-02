#include "SingleChoiceDialog.h"
#include "ui_SingleChoiceDialog.h"
#include "SingleChoiceQuestion.h"
#include <QRadioButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QRegularExpression>

SingleChoiceDialog::SingleChoiceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingleChoiceDialog)
{
    ui->setupUi(this);
}

SingleChoiceDialog::~SingleChoiceDialog()
{
    delete ui;
}

std::shared_ptr<Question> SingleChoiceDialog::getQuestion()
{
    // 获取题干和分值
    QString description = ui->descriptionEdit->text();
    int score = ui->scoreSpinBox->value();

    if (description.isEmpty()) {
        QMessageBox::warning(this, "错误", "题干不能为空");
        return nullptr;
    }

    // 收集选项
    std::vector<std::string> options;

    // 查找所有选项编辑框
    QList<QLineEdit*> optionEdits = findChildren<QLineEdit*>(QRegularExpression("option\\d+Edit"));
    for (QLineEdit* edit : optionEdits) {
        if (!edit->text().isEmpty()) {
            options.push_back(edit->text().toStdString());
        }
    }

    if (options.size() < 2) {
        QMessageBox::warning(this, "错误", "至少需要两个选项");
        return nullptr;
    }

    // 查找正确答案
    int correctIndex = -1;
    QList<QRadioButton*> radioButtons = findChildren<QRadioButton*>(QRegularExpression("option\\d+Radio"));
    for (int i = 0; i < radioButtons.size(); ++i) {
        if (radioButtons[i]->isChecked()) {
            correctIndex = i;
            break;
        }
    }

    if (correctIndex == -1) {
        QMessageBox::warning(this, "错误", "请选择一个正确答案");
        return nullptr;
    }

    // 创建单选题对象
    return std::make_shared<SingleChoiceQuestion>(
        description.toStdString(),
        score,
        options,
        correctIndex
        );
}

void SingleChoiceDialog::on_addOptionButton_clicked()
{
    // 获取当前选项数量
    QList<QLineEdit*> optionEdits = findChildren<QLineEdit*>(QRegularExpression("option\\d+Edit"));
    int optionCount = optionEdits.size();

    if (optionCount >= 10) {
        QMessageBox::warning(this, "错误", "最多只能添加10个选项");
        return;
    }

    // 获取选项组的布局
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->optionsGroup->layout());
    if (!layout) {
        layout = new QVBoxLayout(ui->optionsGroup);
        ui->optionsGroup->setLayout(layout);
    }

    // 创建新的选项行
    QHBoxLayout* optionLayout = new QHBoxLayout();

    QRadioButton* radioButton = new QRadioButton();
    radioButton->setObjectName(QString("option%1Radio").arg(optionCount + 1));

    QLineEdit* lineEdit = new QLineEdit();
    lineEdit->setObjectName(QString("option%1Edit").arg(optionCount + 1));
    lineEdit->setPlaceholderText(QString("选项 %1").arg(optionCount + 1));

    optionLayout->addWidget(radioButton);
    optionLayout->addWidget(lineEdit);

    layout->addLayout(optionLayout);
}

void SingleChoiceDialog::on_removeOptionButton_clicked()
{
    // 获取当前选项数量
    QList<QLineEdit*> optionEdits = findChildren<QLineEdit*>(QRegularExpression("option\\d+Edit"));
    int optionCount = optionEdits.size();

    if (optionCount <= 2) {
        QMessageBox::warning(this, "错误", "至少需要两个选项");
        return;
    }

    // 获取选项组的布局
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->optionsGroup->layout());
    if (!layout || layout->count() == 0) {
        return;
    }

    // 删除最后一个选项
    QLayoutItem* item = layout->takeAt(layout->count() - 1);
    if (item && item->layout()) {
        QLayout* optionLayout = item->layout();
        // 删除布局中的控件
        while (QLayoutItem* child = optionLayout->takeAt(0)) {
            if (child->widget()) {
                delete child->widget();
            }
            delete child;
        }
        delete optionLayout;
    }
    delete item;
}

#include "MultipleChoiceDialog.h"
#include "ui_MultipleChoiceDialog.h"
#include "MultipleChoiceQuestion.h"
#include <QCheckBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QRegularExpression>

MultipleChoiceDialog::MultipleChoiceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MultipleChoiceDialog)
{
    ui->setupUi(this);
}

MultipleChoiceDialog::~MultipleChoiceDialog()
{
    delete ui;
}

std::shared_ptr<Question> MultipleChoiceDialog::getQuestion()
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
    std::vector<int> correctIndices;
    QList<QCheckBox*> checkBoxes = findChildren<QCheckBox*>(QRegularExpression("option\\d+Check"));
    for (int i = 0; i < checkBoxes.size(); ++i) {
        if (checkBoxes[i]->isChecked()) {
            correctIndices.push_back(i);
        }
    }

    if (correctIndices.empty()) {
        QMessageBox::warning(this, "错误", "请至少选择一个正确答案");
        return nullptr;
    }

    // 创建多选题对象
    return std::make_shared<MultipleChoiceQuestion>(
        description.toStdString(),
        score,
        options,
        correctIndices
        );
}

void MultipleChoiceDialog::on_addOptionButton_clicked()
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

    QCheckBox* checkBox = new QCheckBox();
    checkBox->setObjectName(QString("option%1Check").arg(optionCount + 1));

    QLineEdit* lineEdit = new QLineEdit();
    lineEdit->setObjectName(QString("option%1Edit").arg(optionCount + 1));
    lineEdit->setPlaceholderText(QString("选项 %1").arg(optionCount + 1));

    optionLayout->addWidget(checkBox);
    optionLayout->addWidget(lineEdit);

    layout->addLayout(optionLayout);
}

void MultipleChoiceDialog::on_removeOptionButton_clicked()
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

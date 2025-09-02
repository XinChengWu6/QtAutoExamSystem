#include "JudgementDialog.h"
#include "ui_JudgementDialog.h"
#include "JudgementQuestion.h"
#include <QMessageBox>

JudgementDialog::JudgementDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JudgementDialog)
{
    ui->setupUi(this);
}

JudgementDialog::~JudgementDialog()
{
    delete ui;
}

std::shared_ptr<Question> JudgementDialog::getQuestion()
{
    // 获取题干和分值
    QString description = ui->descriptionEdit->text();
    int score = ui->scoreSpinBox->value();

    if (description.isEmpty()) {
        QMessageBox::warning(this, "错误", "题干不能为空");
        return nullptr;
    }

    // 获取正确答案
    bool correctAnswer = ui->trueButton->isChecked();

    // 创建判断题对象
    return std::make_shared<JudgementQuestion>(
        description.toStdString(),
        score,
        correctAnswer
        );
}

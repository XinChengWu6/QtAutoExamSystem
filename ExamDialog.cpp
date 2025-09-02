#include "ExamDialog.h"
#include "ui_ExamDialog.h"
#include "SingleChoiceQuestion.h"
#include "MultipleChoiceQuestion.h"
#include "JudgementQuestion.h"
#include "EssayQuestion.h"
#include <QRadioButton>
#include <QCheckBox>
#include <QButtonGroup>
#include <QTextEdit>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

ExamDialog::ExamDialog(std::shared_ptr<ExamSystem> examSystem, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExamDialog),
    examSystem(examSystem),
    currentIndex(0)
{
    ui->setupUi(this);
    loadQuestion(0);
}

ExamDialog::~ExamDialog()
{
    delete ui;
}

void ExamDialog::loadQuestion(int index)
{
    currentIndex = index;
    auto question = examSystem->getCurrentPaper()->getQuestion(index);

    // 显示题目信息
    QString questionText = QString("第%1题 (%2分): %3")
                               .arg(index + 1)
                               .arg(question->getScore())
                               .arg(QString::fromStdString(question->getDescription()));

    ui->questionLabel->setText(questionText);

    // 清除之前的答题控件
    QLayout* oldLayout = ui->answerWidget->layout();
    if (oldLayout) {
        QLayoutItem* item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    // 创建新的答题控件
    if (question->getType() == "单选题") {
        setupSingleChoiceUI(question);
    } else if (question->getType() == "多选题") {
        setupMultipleChoiceUI(question);
    } else if (question->getType() == "判断题") {
        setupJudgementUI(question);
    } else if (question->getType() == "问答题") {
        setupEssayUI(question);
    }

    // 更新导航按钮状态
    ui->prevButton->setEnabled(index > 0);
    ui->nextButton->setEnabled(index < examSystem->getCurrentPaper()->getQuestionCount() - 1);
}

void ExamDialog::setupSingleChoiceUI(std::shared_ptr<Question> question)
{
    QVBoxLayout* layout = new QVBoxLayout(ui->answerWidget);
    auto singleChoice = std::dynamic_pointer_cast<SingleChoiceQuestion>(question);

    QButtonGroup* buttonGroup = new QButtonGroup(this);

    for (int i = 0; i < singleChoice->getOptions().size(); ++i) {
        QRadioButton* radioButton = new QRadioButton(
            QString::fromStdString(singleChoice->getOptions()[i]));
        layout->addWidget(radioButton);
        buttonGroup->addButton(radioButton, i);
    }

    // 如果已经有答案，选中对应的选项
    // 这里需要从examSystem中获取学生答案
}

void ExamDialog::setupMultipleChoiceUI(std::shared_ptr<Question> question)
{
    QVBoxLayout* layout = new QVBoxLayout(ui->answerWidget);
    auto multiChoice = std::dynamic_pointer_cast<MultipleChoiceQuestion>(question);

    for (int i = 0; i < multiChoice->getOptions().size(); ++i) {
        QCheckBox* checkBox = new QCheckBox(
            QString::fromStdString(multiChoice->getOptions()[i]));
        layout->addWidget(checkBox);
    }

    // 如果已经有答案，选中对应的选项
}

void ExamDialog::setupJudgementUI(std::shared_ptr<Question> question)
{
    QHBoxLayout* layout = new QHBoxLayout(ui->answerWidget);

    QRadioButton* trueButton = new QRadioButton("正确");
    QRadioButton* falseButton = new QRadioButton("错误");

    layout->addWidget(trueButton);
    layout->addWidget(falseButton);

    QButtonGroup* buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(trueButton, 1);
    buttonGroup->addButton(falseButton, 0);

    // 如果已经有答案，选中对应的选项
}

void ExamDialog::setupEssayUI(std::shared_ptr<Question> question)
{
    QVBoxLayout* layout = new QVBoxLayout(ui->answerWidget);

    QTextEdit* textEdit = new QTextEdit();
    layout->addWidget(textEdit);

    // 如果已经有答案，填充文本
}

void ExamDialog::saveAnswer()
{
    // 保存当前题目的答案到examSystem
    // 根据题目类型获取答案
    // 这里需要实现具体的答案保存逻辑
}

void ExamDialog::on_prevButton_clicked()
{
    saveAnswer();
    loadQuestion(currentIndex - 1);
}

void ExamDialog::on_nextButton_clicked()
{
    saveAnswer();
    loadQuestion(currentIndex + 1);
}

void ExamDialog::on_submitButton_clicked()
{
    saveAnswer();

    int score = examSystem->submitExam();
    QMessageBox::information(this, "考试结果",
                             QString("考试结束！您的得分: %1").arg(score));

    accept();
}

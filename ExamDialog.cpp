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
    // 创建垂直布局，用于放置单选按钮
    QVBoxLayout* layout = new QVBoxLayout(ui->answerWidget);
    // 将通用Question指针转换为单选题专用指针（获取选项等信息）
    auto singleChoice = std::dynamic_pointer_cast<SingleChoiceQuestion>(question);

    // 创建按钮组，管理所有单选按钮（确保只能选一个）
    QButtonGroup* buttonGroup = new QButtonGroup(this);
    // 初始化：当前未选中任何选项（-1表示无效索引）
    currentSingleChoiceAnswer = -1;

    // 循环创建单选按钮（每个选项对应一个按钮）
    for (int i = 0; i < singleChoice->getOptions().size(); ++i) {
        // 创建单选按钮，显示选项文本（如"A. 选项内容"）
        QRadioButton* radioButton = new QRadioButton(
            QString::fromStdString(singleChoice->getOptions()[i]));
        // 将按钮添加到布局中（显示在界面上）
        layout->addWidget(radioButton);
        // 将按钮添加到按钮组，并用ID标记为选项索引（0、1、2...）
        buttonGroup->addButton(radioButton, i);
    }

    // 关键：关联按钮组的"选中状态变化"信号
    // 当任何单选按钮被选中/取消时，触发这个lambda函数
    connect(buttonGroup, QOverload<int, bool>::of(&QButtonGroup::idToggled),
            [this](int buttonId, bool isChecked) {
                // 只有当按钮"被选中"时，才更新记录（取消选中时不处理）
                if (isChecked) {
                    // 用buttonId（即选项索引）更新当前选中的答案
                    currentSingleChoiceAnswer = buttonId;
                }
            });
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
    // 1. 获取当前正在作答的题目（通过currentIndex索引）
    auto currentQuestion = examSystem->getCurrentPaper()->getQuestion(currentIndex);
    if (!currentQuestion) {
        return; // 题目无效，直接返回
    }

    // 2. 只处理单选题（其他题型可后续补充）
    if (currentQuestion->getType() == "单选题") {
        // 3. 将选中的选项索引转换为字符串（如2 → "2"）
        // 注意：如果未选择（currentSingleChoiceAnswer = -1），则保存空字符串
        std::string answerStr = (currentSingleChoiceAnswer != -1)
                                    ? std::to_string(currentSingleChoiceAnswer)
                                    : "";

        // 4. 调用ExamSystem的接口，将答案保存到系统中
        // 参数：currentIndex（当前题目索引）、answerStr（转换后的答案）
        examSystem->submitAnswer(currentIndex, answerStr);
    }
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

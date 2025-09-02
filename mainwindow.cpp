#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "SingleChoiceDialog.h"
#include "MultipleChoiceDialog.h"
#include "JudgementDialog.h"
#include "EssayDialog.h"
#include "ExamDialog.h"
#include "SingleChoiceQuestion.h"
#include "MultipleChoiceQuestion.h"
#include "JudgementQuestion.h"
#include "EssayQuestion.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    examSystem = std::make_shared<ExamSystem>();

    // 设置表格列数
    ui->questionTable->setColumnCount(3);
    ui->questionTable->setHorizontalHeaderLabels({"编号", "类型", "分值"});
    ui->questionTable->horizontalHeader()->setStretchLastSection(true);

    updateQuestionList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    examSystem->createNewPaper();
    updateQuestionList();
    ui->statusbar->showMessage("已创建新试卷");
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
        this, "打开试卷", "", "XML文件 (*.xml)");

    if (!filename.isEmpty()) {
        if (examSystem->loadPaperFromFile(filename.toStdString())) {
            updateQuestionList();
            ui->statusbar->showMessage("已加载试卷: " + filename);
        } else {
            QMessageBox::warning(this, "错误", "无法加载试卷文件");
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    if (!examSystem->getCurrentPaper()->validateTotalScore()) {
        QMessageBox::warning(this, "错误",
                             QString("试卷总分不是100分(当前: %1分)，请调整分值")
                                 .arg(examSystem->getCurrentPaper()->calculateTotalScore()));
        return;
    }

    QString filename = QFileDialog::getSaveFileName(
        this, "保存试卷", "", "XML文件 (*.xml)");

    if (!filename.isEmpty()) {
        if (examSystem->savePaperToFile(filename.toStdString())) {
            ui->statusbar->showMessage("已保存试卷: " + filename);
        } else {
            QMessageBox::warning(this, "错误", "无法保存试卷文件");
        }
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAddSingleChoice_triggered()
{
    SingleChoiceDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        auto question = dialog.getQuestion();
        if (question) {
            examSystem->addQuestionToPaper(question);
            updateQuestionList();
        }
    }
}

void MainWindow::on_actionAddMultipleChoice_triggered()
{
    MultipleChoiceDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        auto question = dialog.getQuestion();
        if (question) {
            examSystem->addQuestionToPaper(question);
            updateQuestionList();
        }
    }
}

void MainWindow::on_actionAddJudgement_triggered()
{
    JudgementDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        auto question = dialog.getQuestion();
        if (question) {
            examSystem->addQuestionToPaper(question);
            updateQuestionList();
        }
    }
}

void MainWindow::on_actionAddEssay_triggered()
{
    EssayDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        auto question = dialog.getQuestion();
        if (question) {
            examSystem->addQuestionToPaper(question);
            updateQuestionList();
        }
    }
}

void MainWindow::on_actionStartExam_triggered()
{
    try {
        examSystem->startExam();
        ExamDialog dialog(examSystem, this);
        dialog.exec();
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "错误", e.what());
    }
}

void MainWindow::on_questionTable_itemDoubleClicked(QTableWidgetItem *item)
{
    int row = item->row();
    auto question = examSystem->getCurrentPaper()->getQuestion(row);

    QString message = QString("题目类型: %1\n分值: %2\n题干: %3")
                          .arg(QString::fromStdString(question->getType()))
                          .arg(question->getScore())
                          .arg(QString::fromStdString(question->getDescription()));

    QMessageBox::information(this, "题目详情", message);
}

void MainWindow::updateQuestionList()
{
    ui->questionTable->setRowCount(examSystem->getCurrentPaper()->getQuestionCount());

    for (int i = 0; i < examSystem->getCurrentPaper()->getQuestionCount(); ++i) {
        auto question = examSystem->getCurrentPaper()->getQuestion(i);

        ui->questionTable->setItem(i, 0, new QTableWidgetItem(QString::number(i + 1)));
        ui->questionTable->setItem(i, 1, new QTableWidgetItem(
                                             QString::fromStdString(question->getType())));
        ui->questionTable->setItem(i, 2, new QTableWidgetItem(
                                             QString::number(question->getScore())));
    }

    // 更新状态栏显示总分
    int totalScore = examSystem->getCurrentPaper()->calculateTotalScore();
    ui->statusbar->showMessage(QString("题目数量: %1, 总分: %2")
                                   .arg(examSystem->getCurrentPaper()->getQuestionCount())
                                   .arg(totalScore));
}

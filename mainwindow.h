#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "ExamSystem.h"
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionExit_triggered();

    void on_actionAddSingleChoice_triggered();
    void on_actionAddMultipleChoice_triggered();
    void on_actionAddJudgement_triggered();
    void on_actionAddEssay_triggered();

    void on_actionStartExam_triggered();

    void on_questionTable_itemDoubleClicked(QTableWidgetItem *item);

private:
    void updateQuestionList();

    Ui::MainWindow *ui;
    std::shared_ptr<ExamSystem> examSystem;
};

#endif // MAINWINDOW_H

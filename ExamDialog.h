#ifndef EXAMDIALOG_H
#define EXAMDIALOG_H

#include <QDialog>
#include <memory>
#include "ExamSystem.h"

namespace Ui {
class ExamDialog;
}

class ExamDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExamDialog(std::shared_ptr<ExamSystem> examSystem, QWidget *parent = nullptr);
    ~ExamDialog();

private slots:
    void on_prevButton_clicked();
    void on_nextButton_clicked();
    void on_submitButton_clicked();

private:
    void loadQuestion(int index);
    void setupSingleChoiceUI(std::shared_ptr<Question> question);
    void setupMultipleChoiceUI(std::shared_ptr<Question> question);
    void setupJudgementUI(std::shared_ptr<Question> question);
    void setupEssayUI(std::shared_ptr<Question> question);
    void saveAnswer();

    Ui::ExamDialog *ui;
    std::shared_ptr<ExamSystem> examSystem;
    int currentIndex;
   int currentSingleChoiceAnswer;
};

#endif // EXAMDIALOG_H

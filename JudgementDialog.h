#ifndef JUDGEMENTDIALOG_H
#define JUDGEMENTDIALOG_H

#include <QDialog>
#include <memory>
#include "Question.h"

namespace Ui {
class JudgementDialog;
}

class JudgementDialog : public QDialog
{
    Q_OBJECT

public:
    explicit JudgementDialog(QWidget *parent = nullptr);
    ~JudgementDialog();

    std::shared_ptr<Question> getQuestion();

private:
    Ui::JudgementDialog *ui;
};

#endif // JUDGEMENTDIALOG_H

#ifndef ESSAYDIALOG_H
#define ESSAYDIALOG_H

#include <QDialog>
#include <memory>
#include "Question.h"

namespace Ui {
class EssayDialog;
}

class EssayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EssayDialog(QWidget *parent = nullptr);
    ~EssayDialog();

    std::shared_ptr<Question> getQuestion();

private:
    Ui::EssayDialog *ui;
};

#endif // ESSAYDIALOG_H

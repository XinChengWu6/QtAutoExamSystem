#ifndef MULTIPLECHOICEDIALOG_H
#define MULTIPLECHOICEDIALOG_H

#include <QDialog>
#include <memory>
#include "Question.h"

namespace Ui {
class MultipleChoiceDialog;
}

class MultipleChoiceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MultipleChoiceDialog(QWidget *parent = nullptr);
    ~MultipleChoiceDialog();

    std::shared_ptr<Question> getQuestion();

private slots:
    void on_addOptionButton_clicked();
    void on_removeOptionButton_clicked();

private:
    Ui::MultipleChoiceDialog *ui;
};

#endif // MULTIPLECHOICEDIALOG_H

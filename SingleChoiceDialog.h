#ifndef SINGLECHOICEDIALOG_H
#define SINGLECHOICEDIALOG_H

#include <QDialog>
#include <memory>
#include "Question.h"

namespace Ui {
class SingleChoiceDialog;
}

class SingleChoiceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SingleChoiceDialog(QWidget *parent = nullptr);
    ~SingleChoiceDialog();

    std::shared_ptr<Question> getQuestion();

private slots:
    void on_addOptionButton_clicked();
    void on_removeOptionButton_clicked();

private:
    Ui::SingleChoiceDialog *ui;
};

#endif // SINGLECHOICEDIALOG_H

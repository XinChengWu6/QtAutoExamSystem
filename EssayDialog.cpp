#include "ui_EssayDialog.h"
#include "EssayDialog.h"
#include "EssayQuestion.h"
#include <QMessageBox>

EssayDialog::EssayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EssayDialog)
{
    ui->setupUi(this);
}

EssayDialog::~EssayDialog()
{
    delete ui;
}

std::shared_ptr<Question> EssayDialog::getQuestion()
{
    // 获取题干和分值
    QString description = ui->descriptionEdit->text();
    int score = ui->scoreSpinBox->value();

    if (description.isEmpty()) {
        QMessageBox::warning(this, "错误", "题干不能为空");
        return nullptr;
    }

    // 获取关键词（修复：支持中英文逗号分割）
    QString keywordsText = ui->keywordsEdit->text();
    // 1. 将中文逗号替换为英文逗号，统一分隔符
    keywordsText.replace("，", ",");
    // 2. 按英文逗号分割，跳过空项
    QStringList keywordList = keywordsText.split(',', Qt::SkipEmptyParts);

    std::vector<std::string> keywords;
    for (const QString& keyword : keywordList) {
        // 去除关键词前后空格
        QString trimmed = keyword.trimmed();
        if (!trimmed.isEmpty()) {
            keywords.push_back(trimmed.toStdString());
        }
    }

    if (keywords.empty()) {
        QMessageBox::warning(this, "错误", "请至少输入一个关键词");
        return nullptr;
    }

    // 获取评分规则（不变）
    EssayQuestion::ScoringRule rule;
    if (ui->containsAnyRadio->isChecked()) {
        rule = EssayQuestion::CONTAINS_ANY;
    } else if (ui->containsAllRadio->isChecked()) {
        rule = EssayQuestion::CONTAINS_ALL;
    } else {
        rule = EssayQuestion::COUNT_KEYWORDS;
    }

    // 创建问答题对象
    return std::make_shared<EssayQuestion>(
        description.toStdString(),
        score,
        keywords,
        rule
        );
}

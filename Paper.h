#ifndef PAPER_H
#define PAPER_H

#include "Question.h"
#include <vector>
#include <memory>

class Paper {
public:
    Paper();
    ~Paper();

    // 添加题目
    void addQuestion(std::shared_ptr<Question> question);

    // 删除题目
    void removeQuestion(int index);

    // 获取题目数量
    int getQuestionCount() const;

    // 获取指定题目
    std::shared_ptr<Question> getQuestion(int index) const;

    // 计算总分
    int calculateTotalScore() const;

    // 验证总分是否为100
    bool validateTotalScore() const;

    // 清空试卷
    void clear();

private:
    std::vector<std::shared_ptr<Question>> questions; // 题目列表
};

#endif // PAPER_H

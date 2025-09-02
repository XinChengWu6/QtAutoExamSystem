#ifndef JUDGEMENTQUESTION_H
#define JUDGEMENTQUESTION_H

#include "Question.h"

class JudgementQuestion : public Question {
public:
    JudgementQuestion(const std::string& description, int score, bool correctAnswer);

    // 获取正确答案
    bool getCorrectAnswer() const;

    // 设置正确答案
    void setCorrectAnswer(bool correct);

    // 重写评分函数
    int gradeAnswer(const std::string& answer) const override;

    // 重写保存到文件函数
    void saveToFile(const std::string& filename) const override;

    // 重写获取题型名称函数
    std::string getType() const override;

private:
    bool correctAnswer; // 正确答案(true/false)
};

#endif // JUDGEMENTQUESTION_H

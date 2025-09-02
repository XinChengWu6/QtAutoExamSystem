#ifndef SINGLECHOICEQUESTION_H
#define SINGLECHOICEQUESTION_H

#include "ChoiceQuestion.h"

class SingleChoiceQuestion : public ChoiceQuestion {
public:
    SingleChoiceQuestion(const std::string& description, int score,
                         const std::vector<std::string>& options, int correctAnswer);

    // 获取正确答案索引
    int getCorrectAnswer() const;

    // 设置正确答案
    void setCorrectAnswer(int index);

    // 重写评分函数
    int gradeAnswer(const std::string& answer) const override;

    // 重写保存到文件函数
    void saveToFile(const std::string& filename) const override;

    // 重写获取题型名称函数
    std::string getType() const override;

private:
    int correctAnswer; // 正确答案的索引
};

#endif // SINGLECHOICEQUESTION_H

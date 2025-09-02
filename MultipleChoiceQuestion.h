#ifndef MULTIPLECHOICEQUESTION_H
#define MULTIPLECHOICEQUESTION_H

#include "ChoiceQuestion.h"
#include <vector>

class MultipleChoiceQuestion : public ChoiceQuestion {
public:
    MultipleChoiceQuestion(const std::string& description, int score,
                           const std::vector<std::string>& options,
                           const std::vector<int>& correctAnswers);

    // 获取正确答案索引列表
    std::vector<int> getCorrectAnswers() const;

    // 设置正确答案
    void setCorrectAnswers(const std::vector<int>& answers);

    // 添加正确答案
    void addCorrectAnswer(int index);

    // 移除正确答案
    void removeCorrectAnswer(int index);

    // 重写评分函数
    int gradeAnswer(const std::string& answer) const override;

    // 重写保存到文件函数
    void saveToFile(const std::string& filename) const override;

    // 重写获取题型名称函数
    std::string getType() const override;

private:
    std::vector<int> correctAnswers; // 正确答案的索引列表
};

#endif // MULTIPLECHOICEQUESTION_H

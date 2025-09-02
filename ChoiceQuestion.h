#ifndef CHOICEQUESTION_H
#define CHOICEQUESTION_H

#include "Question.h"
#include <vector>
#include <string>

class ChoiceQuestion : public Question {
public:
    ChoiceQuestion(const std::string& description, int score,
                   const std::vector<std::string>& options);

    // 获取选项
    std::vector<std::string> getOptions() const;

    // 添加选项
    void addOption(const std::string& option);

    // 删除选项
    void removeOption(int index);

protected:
    std::vector<std::string> options;
};

#endif // CHOICEQUESTION_H

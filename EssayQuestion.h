#ifndef ESSAYQUESTION_H
#define ESSAYQUESTION_H

#include "Question.h"
#include <vector>
#include <string>

class EssayQuestion : public Question {
public:
    // 评分规则枚举
    enum ScoringRule {
        CONTAINS_ANY,    // 包含任意关键词即得分
        CONTAINS_ALL,    // 包含所有关键词才得分
        COUNT_KEYWORDS   // 根据包含关键词数量按比例得分
    };

    EssayQuestion(const std::string& description, int score,
                  const std::vector<std::string>& keywords, ScoringRule rule);

    // 获取关键词列表
    std::vector<std::string> getKeywords() const;

    // 添加关键词
    void addKeyword(const std::string& keyword);

    // 移除关键词
    void removeKeyword(int index);

    // 获取评分规则
    ScoringRule getScoringRule() const;

    // 设置评分规则
    void setScoringRule(ScoringRule rule);

    // 重写评分函数
    int gradeAnswer(const std::string& answer) const override;

    // 重写保存到文件函数
    void saveToFile(const std::string& filename) const override;

    // 重写获取题型名称函数
    std::string getType() const override;

private:
    std::vector<std::string> keywords; // 关键词列表
    ScoringRule scoringRule;           // 评分规则
};

#endif // ESSAYQUESTION_H

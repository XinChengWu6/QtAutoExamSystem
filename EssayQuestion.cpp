#include "EssayQuestion.h"
#include <algorithm>
#include <cctype>

EssayQuestion::EssayQuestion(const std::string& description, int score,
                             const std::vector<std::string>& keywords, ScoringRule rule)
    : Question(description, score), keywords(keywords), scoringRule(rule) {}

std::vector<std::string> EssayQuestion::getKeywords() const {
    return keywords;
}

void EssayQuestion::addKeyword(const std::string& keyword) {
    keywords.push_back(keyword);
}

void EssayQuestion::removeKeyword(int index) {
    if (index >= 0 && index < keywords.size()) {
        keywords.erase(keywords.begin() + index);
    }
}

EssayQuestion::ScoringRule EssayQuestion::getScoringRule() const {
    return scoringRule;
}

void EssayQuestion::setScoringRule(ScoringRule rule) {
    scoringRule = rule;
}

int EssayQuestion::gradeAnswer(const std::string& answer) const {
    if (keywords.empty()) {
        return 0;
    }

    // 将答案转换为小写以便匹配
    std::string lowerAnswer = answer;
    std::transform(lowerAnswer.begin(), lowerAnswer.end(), lowerAnswer.begin(), ::tolower);

    int matchedCount = 0;
    for (const auto& keyword : keywords) {
        // 将关键词转换为小写
        std::string lowerKeyword = keyword;
        std::transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), ::tolower);

        // 检查答案是否包含关键词
        if (lowerAnswer.find(lowerKeyword) != std::string::npos) {
            matchedCount++;
        }
    }

    switch (scoringRule) {
    case CONTAINS_ANY:
        return (matchedCount > 0) ? getScore() : 0;
    case CONTAINS_ALL:
        return (matchedCount == keywords.size()) ? getScore() : 0;
    case COUNT_KEYWORDS:
        return static_cast<int>(static_cast<float>(matchedCount) /
                                keywords.size() * getScore());
    default:
        return 0;
    }
}

void EssayQuestion::saveToFile(const std::string& filename) const {
    // XML保存实现将在XMLHandler中统一处理
}

std::string EssayQuestion::getType() const {
    return "问答题";
}

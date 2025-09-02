#include "JudgementQuestion.h"
#include <cctype>
#include <algorithm>

JudgementQuestion::JudgementQuestion(const std::string& description, int score, bool correctAnswer)
    : Question(description, score), correctAnswer(correctAnswer) {}

bool JudgementQuestion::getCorrectAnswer() const {
    return correctAnswer;
}

void JudgementQuestion::setCorrectAnswer(bool correct) {
    correctAnswer = correct;
}

int JudgementQuestion::gradeAnswer(const std::string& answer) const {
    // 转换为小写以便比较
    std::string lowerAnswer = answer;
    std::transform(lowerAnswer.begin(), lowerAnswer.end(), lowerAnswer.begin(), ::tolower);

    bool isTrue = (lowerAnswer == "true" || lowerAnswer == "t" ||
                   lowerAnswer == "对" || lowerAnswer == "正确" ||
                   lowerAnswer == "是" || lowerAnswer == "1");

    bool isFalse = (lowerAnswer == "false" || lowerAnswer == "f" ||
                    lowerAnswer == "错" || lowerAnswer == "错误" ||
                    lowerAnswer == "否" || lowerAnswer == "0");

    if (isTrue && correctAnswer) {
        return getScore();
    } else if (isFalse && !correctAnswer) {
        return getScore();
    } else {
        return 0;
    }
}

void JudgementQuestion::saveToFile(const std::string& filename) const {
    // XML保存实现将在XMLHandler中统一处理
}

std::string JudgementQuestion::getType() const {
    return "判断题";
}

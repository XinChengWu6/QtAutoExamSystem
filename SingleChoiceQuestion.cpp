#include "SingleChoiceQuestion.h"
#include <stdexcept>

SingleChoiceQuestion::SingleChoiceQuestion(const std::string& description, int score,
                                           const std::vector<std::string>& options, int correctAnswer)
    : ChoiceQuestion(description, score, options), correctAnswer(correctAnswer) {
    if (correctAnswer < 0 || correctAnswer >= options.size()) {
        throw std::out_of_range("正确答案索引超出范围");
    }
}

int SingleChoiceQuestion::getCorrectAnswer() const {
    return correctAnswer;
}

void SingleChoiceQuestion::setCorrectAnswer(int index) {
    if (index < 0 || index >= getOptions().size()) {
        throw std::out_of_range("正确答案索引超出范围");
    }
    correctAnswer = index;
}

int SingleChoiceQuestion::gradeAnswer(const std::string& answer) const {
    try {
        int selected = std::stoi(answer);
        return (selected == correctAnswer) ? getScore() : 0;
    } catch (const std::exception&) {
        return 0;
    }
}

void SingleChoiceQuestion::saveToFile(const std::string& filename) const {
    // XML保存实现将在XMLHandler中统一处理
    // 这里可以留空或调用XMLHandler的方法
}

std::string SingleChoiceQuestion::getType() const {
    return "单选题";
}

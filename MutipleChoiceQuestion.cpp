#include "MultipleChoiceQuestion.h"
#include <algorithm>
#include <sstream>
#include <stdexcept>

MultipleChoiceQuestion::MultipleChoiceQuestion(const std::string& description, int score,
                                               const std::vector<std::string>& options,
                                               const std::vector<int>& correctAnswers)
    : ChoiceQuestion(description, score, options), correctAnswers(correctAnswers) {
    for (int answer : correctAnswers) {
        if (answer < 0 || answer >= options.size()) {
            throw std::out_of_range("正确答案索引超出范围");
        }
    }
}

std::vector<int> MultipleChoiceQuestion::getCorrectAnswers() const {
    return correctAnswers;
}

void MultipleChoiceQuestion::setCorrectAnswers(const std::vector<int>& answers) {
    for (int answer : answers) {
        if (answer < 0 || answer >= getOptions().size()) {
            throw std::out_of_range("正确答案索引超出范围");
        }
    }
    correctAnswers = answers;
}

void MultipleChoiceQuestion::addCorrectAnswer(int index) {
    if (index < 0 || index >= getOptions().size()) {
        throw std::out_of_range("正确答案索引超出范围");
    }
    if (std::find(correctAnswers.begin(), correctAnswers.end(), index) == correctAnswers.end()) {
        correctAnswers.push_back(index);
    }
}

void MultipleChoiceQuestion::removeCorrectAnswer(int index) {
    auto it = std::find(correctAnswers.begin(), correctAnswers.end(), index);
    if (it != correctAnswers.end()) {
        correctAnswers.erase(it);
    }
}

int MultipleChoiceQuestion::gradeAnswer(const std::string& answer) const {
    try {
        // 假设答案格式为"1,3,5"这样的字符串
        std::vector<int> selectedAnswers;
        std::stringstream ss(answer);
        std::string item;

        while (std::getline(ss, item, ',')) {
            selectedAnswers.push_back(std::stoi(item));
        }

        // 排序以便比较
        std::vector<int> correctSorted = correctAnswers;
        std::sort(correctSorted.begin(), correctSorted.end());
        std::sort(selectedAnswers.begin(), selectedAnswers.end());

        // 如果答案完全正确，得满分；否则得0分
        if (correctSorted == selectedAnswers) {
            return getScore();
        } else {
            return 0;
        }
    } catch (const std::exception&) {
        return 0;
    }
}

void MultipleChoiceQuestion::saveToFile(const std::string& filename) const {
    // XML保存实现将在XMLHandler中统一处理
}

std::string MultipleChoiceQuestion::getType() const {
    return "多选题";
}

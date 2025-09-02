#include "Paper.h"

Paper::Paper() {}

Paper::~Paper() {
    clear();
}

void Paper::addQuestion(std::shared_ptr<Question> question) {
    questions.push_back(question);
}

void Paper::removeQuestion(int index) {
    if (index >= 0 && index < questions.size()) {
        questions.erase(questions.begin() + index);
    }
}

int Paper::getQuestionCount() const {
    return questions.size();
}

std::shared_ptr<Question> Paper::getQuestion(int index) const {
    if (index >= 0 && index < questions.size()) {
        return questions[index];
    }
    return nullptr;
}

int Paper::calculateTotalScore() const {
    int total = 0;
    for (const auto& question : questions) {
        total += question->getScore();
    }
    return total;
}

bool Paper::validateTotalScore() const {
    return calculateTotalScore() == 100;
}

void Paper::clear() {
    questions.clear();
}

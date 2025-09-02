#include "Question.h"

Question::Question(const std::string& description, int score)
    : description(description), score(score) {}

std::string Question::getDescription() const {
    return description;
}

int Question::getScore() const {
    return score;
}

void Question::setScore(int score) {
    this->score = score;
}

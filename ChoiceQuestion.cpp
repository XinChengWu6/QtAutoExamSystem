#include "ChoiceQuestion.h"

ChoiceQuestion::ChoiceQuestion(const std::string& description, int score,
                               const std::vector<std::string>& options)
    : Question(description, score), options(options) {}

std::vector<std::string> ChoiceQuestion::getOptions() const {
    return options;
}

void ChoiceQuestion::addOption(const std::string& option) {
    options.push_back(option);
}

void ChoiceQuestion::removeOption(int index) {
    if (index >= 0 && index < options.size()) {
        options.erase(options.begin() + index);
    }
}

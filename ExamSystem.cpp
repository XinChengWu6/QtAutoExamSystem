#include "ExamSystem.h"
#include "XMLHandler.h"
#include <stdexcept>

ExamSystem::ExamSystem() : examInProgress(false) {
    currentPaper = std::make_shared<Paper>();
}

ExamSystem::~ExamSystem() {}

std::shared_ptr<Paper> ExamSystem::getCurrentPaper() const {
    return currentPaper;
}

void ExamSystem::createNewPaper() {
    if (examInProgress) {
        throw std::runtime_error("考试进行中，不能创建新试卷");
    }
    currentPaper = std::make_shared<Paper>();
    studentAnswers.clear();
}

bool ExamSystem::addQuestionToPaper(std::shared_ptr<Question> question) {
    if (examInProgress) {
        return false;
    }
    currentPaper->addQuestion(question);
    return true;
}

bool ExamSystem::removeQuestionFromPaper(int index) {
    if (examInProgress) {
        return false;
    }
    currentPaper->removeQuestion(index);
    return true;
}

void ExamSystem::startExam() {
    if (currentPaper->getQuestionCount() == 0) {
        throw std::runtime_error("试卷为空，无法开始考试");
    }

    if (!currentPaper->validateTotalScore()) {
        throw std::runtime_error("试卷总分不是100分，请调整分值");
    }

    examInProgress = true;
    studentAnswers.clear();
    studentAnswers.resize(currentPaper->getQuestionCount());
}

void ExamSystem::submitAnswer(int questionIndex, const std::string& answer) {
    if (!examInProgress) {
        throw std::runtime_error("考试未开始，无法提交答案");
    }

    if (questionIndex < 0 || questionIndex >= currentPaper->getQuestionCount()) {
        throw std::out_of_range("题目索引超出范围");
    }

    studentAnswers[questionIndex] = answer;
}

int ExamSystem::submitExam() {
    if (!examInProgress) {
        throw std::runtime_error("考试未开始，无法交卷");
    }

    int totalScore = 0;
    for (int i = 0; i < currentPaper->getQuestionCount(); i++) {
        auto question = currentPaper->getQuestion(i);
        totalScore += question->gradeAnswer(studentAnswers[i]);
    }

    examInProgress = false;
    return totalScore;
}

bool ExamSystem::savePaperToFile(const std::string& filename) const {
    return XMLHandler::savePaperToXML(currentPaper, filename);
}

bool ExamSystem::loadPaperFromFile(const std::string& filename) {
    if (examInProgress) {
        return false;
    }

    auto newPaper = XMLHandler::loadPaperFromXML(filename);
    if (newPaper) {
        currentPaper = newPaper;
        return true;
    }
    return false;
}

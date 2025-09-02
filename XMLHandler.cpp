#include "XMLHandler.h"
#include "SingleChoiceQuestion.h"
#include "MultipleChoiceQuestion.h"
#include "JudgementQuestion.h"
#include "EssayQuestion.h"
#include <pugixml.hpp>
#include <memory>

// 使用pugixml库实现XML的读写
bool XMLHandler::savePaperToXML(const std::shared_ptr<Paper>& paper, const std::string& filename) {
    pugi::xml_document doc;

    // 创建根节点
    pugi::xml_node root = doc.append_child("ExamPaper");

    // 添加题目
    for (int i = 0; i < paper->getQuestionCount(); i++) {
        auto question = paper->getQuestion(i);
        pugi::xml_node questionNode = root.append_child("Question");

        // 添加题目类型属性
        questionNode.append_attribute("type") = question->getType().c_str();

        // 添加题目描述
        pugi::xml_node descNode = questionNode.append_child("Description");
        descNode.text().set(question->getDescription().c_str());

        // 添加题目分值
        pugi::xml_node scoreNode = questionNode.append_child("Score");
        scoreNode.text().set(question->getScore());

        // 根据题目类型添加特定信息
        if (question->getType() == "单选题") {
            auto singleChoice = std::dynamic_pointer_cast<SingleChoiceQuestion>(question);
            if (singleChoice) {
                // 添加选项
                pugi::xml_node optionsNode = questionNode.append_child("Options");
                for (const auto& option : singleChoice->getOptions()) {
                    pugi::xml_node optionNode = optionsNode.append_child("Option");
                    optionNode.text().set(option.c_str());
                }

                // 添加正确答案
                pugi::xml_node answerNode = questionNode.append_child("CorrectAnswer");
                answerNode.text().set(singleChoice->getCorrectAnswer());
            }
        } else if (question->getType() == "多选题") {
            auto multiChoice = std::dynamic_pointer_cast<MultipleChoiceQuestion>(question);
            if (multiChoice) {
                // 添加选项
                pugi::xml_node optionsNode = questionNode.append_child("Options");
                for (const auto& option : multiChoice->getOptions()) {
                    pugi::xml_node optionNode = optionsNode.append_child("Option");
                    optionNode.text().set(option.c_str());
                }

                // 添加正确答案
                pugi::xml_node answersNode = questionNode.append_child("CorrectAnswers");
                for (int answer : multiChoice->getCorrectAnswers()) {
                    pugi::xml_node answerNode = answersNode.append_child("Answer");
                    answerNode.text().set(answer);
                }
            }
        } else if (question->getType() == "判断题") {
            auto judgement = std::dynamic_pointer_cast<JudgementQuestion>(question);
            if (judgement) {
                // 添加正确答案
                pugi::xml_node answerNode = questionNode.append_child("CorrectAnswer");
                answerNode.text().set(judgement->getCorrectAnswer());
            }
        } else if (question->getType() == "问答题") {
            auto essay = std::dynamic_pointer_cast<EssayQuestion>(question);
            if (essay) {
                // 添加关键词
                pugi::xml_node keywordsNode = questionNode.append_child("Keywords");
                for (const auto& keyword : essay->getKeywords()) {
                    pugi::xml_node keywordNode = keywordsNode.append_child("Keyword");
                    keywordNode.text().set(keyword.c_str());
                }

                // 添加评分规则
                pugi::xml_node ruleNode = questionNode.append_child("ScoringRule");
                ruleNode.text().set(static_cast<int>(essay->getScoringRule()));
            }
        }
    }

    // 保存文档
    return doc.save_file(filename.c_str());
}

std::shared_ptr<Paper> XMLHandler::loadPaperFromXML(const std::string& filename) {
    pugi::xml_document doc;
    if (!doc.load_file(filename.c_str())) {
        return nullptr;
    }

    auto paper = std::make_shared<Paper>();
    pugi::xml_node root = doc.child("ExamPaper");

    for (pugi::xml_node questionNode : root.children("Question")) {
        std::string type = questionNode.attribute("type").value();
        std::string description = questionNode.child("Description").text().get();
        int score = questionNode.child("Score").text().as_int();

        if (type == "单选题") {
            // 解析选项
            std::vector<std::string> options;
            pugi::xml_node optionsNode = questionNode.child("Options");
            for (pugi::xml_node optionNode : optionsNode.children("Option")) {
                options.push_back(optionNode.text().get());
            }

            // 解析正确答案
            int correctAnswer = questionNode.child("CorrectAnswer").text().as_int();

            // 创建题目对象
            auto question = std::make_shared<SingleChoiceQuestion>(
                description, score, options, correctAnswer);
            paper->addQuestion(question);

        } else if (type == "多选题") {
            // 解析选项
            std::vector<std::string> options;
            pugi::xml_node optionsNode = questionNode.child("Options");
            for (pugi::xml_node optionNode : optionsNode.children("Option")) {
                options.push_back(optionNode.text().get());
            }

            // 解析正确答案
            std::vector<int> correctAnswers;
            pugi::xml_node answersNode = questionNode.child("CorrectAnswers");
            for (pugi::xml_node answerNode : answersNode.children("Answer")) {
                correctAnswers.push_back(answerNode.text().as_int());
            }

            // 创建题目对象
            auto question = std::make_shared<MultipleChoiceQuestion>(
                description, score, options, correctAnswers);
            paper->addQuestion(question);

        } else if (type == "判断题") {
            // 解析正确答案
            bool correctAnswer = questionNode.child("CorrectAnswer").text().as_bool();

            // 创建题目对象
            auto question = std::make_shared<JudgementQuestion>(
                description, score, correctAnswer);
            paper->addQuestion(question);

        } else if (type == "问答题") {
            // 解析关键词
            std::vector<std::string> keywords;
            pugi::xml_node keywordsNode = questionNode.child("Keywords");
            for (pugi::xml_node keywordNode : keywordsNode.children("Keyword")) {
                keywords.push_back(keywordNode.text().get());
            }

            // 解析评分规则
            EssayQuestion::ScoringRule rule = static_cast<EssayQuestion::ScoringRule>(
                questionNode.child("ScoringRule").text().as_int());

            // 创建题目对象
            auto question = std::make_shared<EssayQuestion>(
                description, score, keywords, rule);
            paper->addQuestion(question);
        }
    }

    return paper;
}

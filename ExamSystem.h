#ifndef EXAMSYSTEM_H
#define EXAMSYSTEM_H

#include "Paper.h"
#include <vector>
#include <string>
#include <memory>

class ExamSystem {
public:
    ExamSystem();
    ~ExamSystem();

    // 获取当前试卷
    std::shared_ptr<Paper> getCurrentPaper() const;

    // 创建新试卷
    void createNewPaper();

    // 添加题目到当前试卷
    bool addQuestionToPaper(std::shared_ptr<Question> question);

    // 从当前试卷删除题目
    bool removeQuestionFromPaper(int index);

    // 开始考试
    void startExam();

    // 提交答案
    void submitAnswer(int questionIndex, const std::string& answer);

    // 交卷并计算总分
    int submitExam();

    // 保存试卷到文件
    bool savePaperToFile(const std::string& filename) const;

    // 从文件加载试卷
    bool loadPaperFromFile(const std::string& filename);

private:
    std::shared_ptr<Paper> currentPaper; // 当前试卷
    std::vector<std::string> studentAnswers; // 学生答案
    bool examInProgress; // 考试是否进行中
};

#endif // EXAMSYSTEM_H

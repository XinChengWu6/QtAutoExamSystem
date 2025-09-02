#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question {
public:
    Question(const std::string& description, int score);
    virtual ~Question() = default;

    // 获取题目描述
    std::string getDescription() const;

    // 获取分值
    int getScore() const;

    // 设置分值
    void setScore(int score);

    // 纯虚函数：评分
    virtual int gradeAnswer(const std::string& answer) const = 0;

    // 纯虚函数：保存到文件
    virtual void saveToFile(const std::string& filename) const = 0;

    // 纯虚函数：获取题型名称
    virtual std::string getType() const = 0;

protected:
    std::string description;
    int score;
};

#endif // QUESTION_H

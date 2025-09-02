#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QStatusBar>
#include <QListWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QTableWidget>
#include <QHeaderView>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QTextEdit>
#include <QButtonGroup>
#include <QGroupBox>

#include "ExamSystem.h"
#include "SingleChoiceQuestion.h"
#include "MultipleChoiceQuestion.h"
#include "JudgementQuestion.h"
#include "EssayQuestion.h"
#include "SingleChoiceDialog.h"
#include "MultipleChoiceDialog.h"
#include "JudgementDialog.h"
#include "EssayDialog.h"
#include "ExamDialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 设置应用程序信息
    QApplication::setApplicationName("自动考试系统");
    QApplication::setApplicationVersion("1.0");
    QApplication::setOrganizationName("教育科技公司");

    // 创建主窗口
    QMainWindow window;
    window.setWindowTitle("自动考试系统");
    window.setMinimumSize(800, 600);

    // 创建考试系统核心对象
    std::shared_ptr<ExamSystem> examSystem = std::make_shared<ExamSystem>();

    // 创建中央部件
    QWidget *centralWidget = new QWidget(&window);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // 创建题目表格
    QTableWidget *questionTable = new QTableWidget(centralWidget);
    questionTable->setColumnCount(3);
    questionTable->setHorizontalHeaderLabels({"编号", "类型", "分值"});
    questionTable->horizontalHeader()->setStretchLastSection(true);
    questionTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    questionTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    mainLayout->addWidget(questionTable);
    window.setCentralWidget(centralWidget);

    // 创建菜单栏
    QMenuBar *menuBar = new QMenuBar(&window);
    window.setMenuBar(menuBar);

    // 文件菜单
    QMenu *fileMenu = menuBar->addMenu("文件");
    QAction *newAction = fileMenu->addAction("新建试卷");
    QAction *openAction = fileMenu->addAction("打开试卷");
    QAction *saveAction = fileMenu->addAction("保存试卷");
    fileMenu->addSeparator();
    QAction *exitAction = fileMenu->addAction("退出");

    // 出题菜单
    QMenu *questionMenu = menuBar->addMenu("出题");
    QAction *singleChoiceAction = questionMenu->addAction("添加单选题");
    QAction *multipleChoiceAction = questionMenu->addAction("添加多选题");
    QAction *judgementAction = questionMenu->addAction("添加判断题");
    QAction *essayAction = questionMenu->addAction("添加问答题");

    // 考试菜单
    QMenu *examMenu = menuBar->addMenu("考试");
    QAction *startExamAction = examMenu->addAction("开始考试");

    // 创建状态栏
    QStatusBar *statusBar = new QStatusBar(&window);
    window.setStatusBar(statusBar);
    statusBar->showMessage("就绪");

    // 更新题目列表的函数
    auto updateQuestionList = [&]() {
        questionTable->setRowCount(examSystem->getCurrentPaper()->getQuestionCount());

        for (int i = 0; i < examSystem->getCurrentPaper()->getQuestionCount(); ++i) {
            auto question = examSystem->getCurrentPaper()->getQuestion(i);

            questionTable->setItem(i, 0, new QTableWidgetItem(QString::number(i + 1)));
            questionTable->setItem(i, 1, new QTableWidgetItem(
                                             QString::fromStdString(question->getType())));
            questionTable->setItem(i, 2, new QTableWidgetItem(
                                             QString::number(question->getScore())));
        }

        // 更新状态栏显示总分
        int totalScore = examSystem->getCurrentPaper()->calculateTotalScore();
        statusBar->showMessage(QString("题目数量: %1, 总分: %2")
                                   .arg(examSystem->getCurrentPaper()->getQuestionCount())
                                   .arg(totalScore));
    };

    // 查看题目详情的函数
    auto viewQuestion = [&](QTableWidgetItem *item) {
        int row = item->row();
        auto question = examSystem->getCurrentPaper()->getQuestion(row);

        QString message = QString("题目类型: %1\n分值: %2\n题干: %3")
                              .arg(QString::fromStdString(question->getType()))
                              .arg(question->getScore())
                              .arg(QString::fromStdString(question->getDescription()));

        QMessageBox::information(&window, "题目详情", message);
    };

    // 连接信号和槽
    QObject::connect(newAction, &QAction::triggered, [&]() {
        examSystem->createNewPaper();
        updateQuestionList();
        statusBar->showMessage("已创建新试卷");
    });

    QObject::connect(openAction, &QAction::triggered, [&]() {
        QString filename = QFileDialog::getOpenFileName(
            &window, "打开试卷", "", "XML文件 (*.xml)");

        if (!filename.isEmpty()) {
            if (examSystem->loadPaperFromFile(filename.toStdString())) {
                updateQuestionList();
                statusBar->showMessage("已加载试卷: " + filename);
            } else {
                QMessageBox::warning(&window, "错误", "无法加载试卷文件");
            }
        }
    });

    QObject::connect(saveAction, &QAction::triggered, [&]() {
        if (!examSystem->getCurrentPaper()->validateTotalScore()) {
            QMessageBox::warning(&window, "错误",
                                 QString("试卷总分不是100分(当前: %1分)，请调整分值")
                                     .arg(examSystem->getCurrentPaper()->calculateTotalScore()));
            return;
        }

        QString filename = QFileDialog::getSaveFileName(
            &window, "保存试卷", "", "XML文件 (*.xml)");

        if (!filename.isEmpty()) {
            if (examSystem->savePaperToFile(filename.toStdString())) {
                statusBar->showMessage("已保存试卷: " + filename);
            } else {
                QMessageBox::warning(&window, "错误", "无法保存试卷文件");
            }
        }
    });

    QObject::connect(exitAction, &QAction::triggered, &QApplication::quit);

    QObject::connect(singleChoiceAction, &QAction::triggered, [&]() {
        SingleChoiceDialog dialog(&window);
        if (dialog.exec() == QDialog::Accepted) {
            auto question = dialog.getQuestion();
            if (question) {
                examSystem->addQuestionToPaper(question);
                updateQuestionList();
            }
        }
    });

    QObject::connect(multipleChoiceAction, &QAction::triggered, [&]() {
        MultipleChoiceDialog dialog(&window);
        if (dialog.exec() == QDialog::Accepted) {
            auto question = dialog.getQuestion();
            if (question) {
                examSystem->addQuestionToPaper(question);
                updateQuestionList();
            }
        }
    });

    QObject::connect(judgementAction, &QAction::triggered, [&]() {
        JudgementDialog dialog(&window);
        if (dialog.exec() == QDialog::Accepted) {
            auto question = dialog.getQuestion();
            if (question) {
                examSystem->addQuestionToPaper(question);
                updateQuestionList();
            }
        }
    });

    QObject::connect(essayAction, &QAction::triggered, [&]() {
        EssayDialog dialog(&window);
        if (dialog.exec() == QDialog::Accepted) {
            auto question = dialog.getQuestion();
            if (question) {
                examSystem->addQuestionToPaper(question);
                updateQuestionList();
            }
        }
    });

    QObject::connect(startExamAction, &QAction::triggered, [&]() {
        try {
            examSystem->startExam();
            ExamDialog dialog(examSystem, &window);
            dialog.exec();
        } catch (const std::exception& e) {
            QMessageBox::warning(&window, "错误", e.what());
        }
    });

    QObject::connect(questionTable, &QTableWidget::itemDoubleClicked, [&](QTableWidgetItem *item) {
        viewQuestion(item);
    });

    // 显示窗口
    window.show();

    // 运行应用程序
    return app.exec();
}

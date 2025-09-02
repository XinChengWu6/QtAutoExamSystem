QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    ChoiceQuestion.cpp \
    EssayDialog.cpp \
    EssayQuestion.cpp \
    ExamDialog.cpp \
    ExamSystem.cpp \
    JudgementDialog.cpp \
    JudgementQuestion.cpp \
    MultiplechoiceDialog.cpp \
    MutipleChoiceQuestion.cpp \
    Paper.cpp \
    Question.cpp \
    SingleChoiceDialog.cpp \
    SingleChoiceQuestion.cpp \
    XMLHandler.cpp \
    main.cpp \
    mainwindow.cpp\
    third_party\pugixml\pugixml.cpp

HEADERS += \
    ChoiceQuestion.h \
    EssayDialog.h \
    EssayQuestion.h \
    ExamDialog.h \
    ExamSystem.h \
    JudgementDialog.h \
    JudgementQuestion.h \
    MultipleChoiceDialog.h \
    MultipleChoiceQuestion.h \
    Paper.h \
    Question.h \
    SingleChoiceDialog.h \
    SingleChoiceQuestion.h \
    XMLHandler.h \
    mainwindow.h

FORMS += \
    EssayDialog.ui \
    ExamDialog.ui \
    JudgementDialog.ui \
    MultipleChoiceDialog.ui \
    SingleChoiceDialog.ui \
    mainwindow.ui

TRANSLATIONS += \
    dpautoexam_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# 用实际路径替换下面的示例路径
INCLUDEPATH += D:\qt\code\dpautoexam\third_party\pugixml

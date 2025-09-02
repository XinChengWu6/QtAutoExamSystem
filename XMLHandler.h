#ifndef XMLHANDLER_H
#define XMLHANDLER_H

#include "Paper.h"
#include <string>

class XMLHandler {
public:
    // 保存试卷到XML文件
    static bool savePaperToXML(const std::shared_ptr<Paper>& paper, const std::string& filename);

    // 从XML文件加载试卷
    static std::shared_ptr<Paper> loadPaperFromXML(const std::string& filename);
};

#endif // XMLHANDLER_H

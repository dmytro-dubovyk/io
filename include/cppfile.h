#ifndef _CPP_FILE_H_
#define _CPP_FILE_H_

#include "file.h"
#include <fstream>
#include <string>

class CppFile final : public File {
public:
    CppFile(const std::string&);
    ~CppFile() override;

    long size() override;
    bool copy() override;

    std::string readText() override;
    bool appendText(const std::string&) override;

private:
    bool open(const std::string& mode = "r") override;
    bool close() override;

    std::fstream mFile;
};

#endif

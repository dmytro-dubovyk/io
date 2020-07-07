#ifndef _C_FILE_H_
#define _C_FILE_H_

#include "file.h"

class CFile final : public File {
public:
    CFile(const std::string&);
    ~CFile() override;
    long size() override;
    bool copy() override;

    std::string readText() override;
    bool appendText(const std::string&) override;

private:
    bool open(const std::string& mode = "r") override;
    bool close() override;

    FILE* mFile;
};

#endif

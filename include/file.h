#ifndef _FILE_H_
#define _FILE_H_

#include <iostream>
#include <string>

class File {
public:
    File(const std::string& fileName)
        : mFileName{fileName}
        , mIsOpen{false} {}
    virtual ~File() = default;
    virtual long size() = 0;
    virtual bool copy() = 0;

    virtual std::string readText() = 0;
    virtual bool appendText(const std::string&) = 0;

    bool isOpen() const { return mIsOpen; }

protected:
    virtual bool open(const std::string& mode = "r") = 0;
    virtual bool close() = 0;

    std::string mFileName;
    bool mIsOpen;
};

#endif

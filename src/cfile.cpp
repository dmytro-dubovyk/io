#include "cfile.h"
#include <stdio.h>

CFile::CFile(const std::string& fileName)
    : File(fileName)
    , mFile{nullptr} {
    open();
}

CFile::~CFile() {
    close();
}

bool CFile::open(const std::string& mode) {
    mFile = fopen(mFileName.c_str(), mode.c_str());
    if (mFile != nullptr) {
        mIsOpen = true;
    }

    return mIsOpen;
}

bool CFile::close() {
    auto result{0};
    if (mFile) {
        result = fclose(mFile);
    }

    if (result == 0) {
        mIsOpen = false;
    }

    return !mIsOpen;
}

long CFile::size() {
    const auto originalPosition{ftell(mFile)};
    fseek(mFile, 0L, SEEK_END);
    const auto size{ftell(mFile)};
    fseek(mFile, originalPosition, SEEK_SET);

    return size;
}

bool CFile::copy() {
    char buff[255];
    size_t bytesRead{};
    size_t bytesTotal{};
    size_t bytesWritten{};
    const auto cpyFileName = mFileName + ".cpy";

    mFile = freopen(mFileName.c_str(), "rb", mFile);
    FILE* out = fopen(cpyFileName.c_str(), "wb");
    while ((bytesRead = fread(buff, sizeof(char), BUFSIZ, mFile)) != 0 ) {
        bytesTotal += bytesRead;
        bytesWritten += fwrite(buff, sizeof(char), bytesRead, out);
    }

    fclose(out);
    close();
    open();
    return (bytesTotal == bytesWritten);
}

std::string CFile::readText() {
    constexpr auto kBufSize{255};
    char buf[255]{};
    std::string s{};
    fseek(mFile, 0L, SEEK_SET);
    while (fgets(buf, kBufSize, mFile) != nullptr) {
        s.append(buf);
    }

    return s;
}

bool CFile::appendText(const std::string& text) {
    mFile = freopen(mFileName.c_str(), "a+", mFile);
    fseek(mFile, 0L, SEEK_END);
//    auto result = fputs(text.c_str(), mFile);
    auto result = fwrite(text.c_str(), sizeof(char), text.length(), mFile);
    close();
    open();
    return (result == text.length());
}

#include "cppfile.h"

constexpr auto kAppend{"append"};

CppFile::CppFile(const std::string& fileName)
    : File{fileName} {
    open();
}

CppFile::~CppFile() {
    close();
}

bool CppFile::open(const std::string& mode) {
    std::ios::openmode flags{std::ios::in};
    if (mode == kAppend) {
        flags |= std::ios::app | std::ios::out;
    }

    mFile.open(mFileName, flags);
    mIsOpen = (mFile.is_open() && mFile.good());

    return mIsOpen;
}

bool CppFile::close() {
    if (mFile.is_open()) {
        mFile.sync();
        mFile.close();
        mIsOpen = mFile.is_open();
    }
    return mIsOpen;
}

long CppFile::size() {
    const auto originalPosition{mFile.tellg()};
    mFile.seekg(0, std::ios::end);
    const auto size{mFile.tellg()};
    //mFile.seekg (0, std::ios::beg);
    mFile.seekg(originalPosition);
    return size;
}

bool CppFile::copy() {
    return false;
}

std::string CppFile::readText() {
    if (!mFile.is_open()) { open(); }
    std::string s{};
    std::string result{};
    mFile.seekg(std::ios::beg);

    while (std::getline(mFile, s)) {
        result.append(s + "\n");
    }
    return result;
}

bool CppFile::appendText(const std::string& text) {
    close();
    open(kAppend);
    //mFile.seekp(std::ios::end);
    mFile << text;
    close();
    open();
    return true;
}

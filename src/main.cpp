#include <iostream>
#include <memory>
#include "cfile.h"
#include "cppfile.h"
#include "widget.h"

template <class T, class U>
T max (T a, U b) {
    return (a>b ? a : b);
}

// pass a text file as a parameter for the executable
int main(int argc, char** argv) {
    int i{10};
    long j{20};
    int k{max<int, long>(i, j)};
    std::cout << "Max is " << k << std::endl;

    Widget w;
    w.processData();

    if (argc > 1) {
        // use one of the implementations here
        File* file{new CFile(argv[1])};
        //File* file{new CppFile(argv[1])};
        if (file->isOpen()) {
            std::cout << "File size: " << file->size() << std::endl;
            std::cout << file->readText() << std::endl;

            std::cout << "Appending text:" << std::endl;
            file->appendText("Hello World!\n");
            std::cout << file->readText() << std::endl;

            const auto copyResult{file->copy()};
            std::cout << "Copying finished " << (copyResult ? "successfully" : "unsuccessfully")
                      << std::endl;
        }

        delete file;
    }

    return 0;
}

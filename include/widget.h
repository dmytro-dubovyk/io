#ifndef _WIDGET_H_
#define _WIDGET_H_

class Widget final {
public:
    Widget();
    ~Widget();

    void processData();

private:
    struct Impl; // forward declaration
    Impl *pImpl; // pointer to the implementation
};

#endif

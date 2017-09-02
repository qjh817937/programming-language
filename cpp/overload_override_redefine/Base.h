#ifndef BASE_H
#define BASE_H

#include <stdio.h>

class Base {
public:
    Base() {}
    ~Base() {}

    // overload
    void fun1(int a) { printf("Base::fun1(int)\n"); }
    void fun1(int a, int b) { printf("Base::fun1(int,int)\n"); }

    // 
    virtual void fun2(int a) { printf("Base::fun2(int)\n"); } 

    void fun3(int a) { printf("Base::fun3(int)\n"); }
};

#endif // BASE_H

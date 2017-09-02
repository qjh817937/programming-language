#ifndef DERIVE_H
#define DERIVE_H

class Derive: public Base{
public:
    Derive() { }
    ~Derive() { }

    // override
    void fun2(int a) { printf("Derive::fun2(int)\n"); }

    // redefine
    void fun3(int a) { printf("Derive::fun3(int)\n"); }
};

#endif // DERIVE_H

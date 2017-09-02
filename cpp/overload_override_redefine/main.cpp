#include <Base.h>
#include <Derive.h>

int main(int argc, char **args) {
    Derive derive;
    Base *baseP = &derive;
    
    baseP->fun1(1);
    baseP->fun1(1,2);
    baseP->fun2(1);
    baseP->fun3(1);
    return 0;
}

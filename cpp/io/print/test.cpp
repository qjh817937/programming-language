#include "stdio.h"
#include <string>
int main()
{
    printf("%03d\n",10);
    std::string s = "%03d\n";
    char a[10] = "%03d\n";

    printf(a, 10);
    printf(a, 100);
    printf(a, 1000);
    
    printf(s.c_str(), 10);
    printf(s.c_str(), 100);
    printf(s.c_str(), 1000);

    printf("%%0%dd\n", s.size());
}

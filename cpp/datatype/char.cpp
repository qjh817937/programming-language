#include "stdio.h"

void test()
{
    const int num = 300;
    char str[num];
    for(int i = 0; i < num;i++)
    {
        str[i] = (char)i;
        int a = str[i];
        printf("%c %d %u %x %d %d %d\n",str[i], str[i], str[i], str[i], a, +str[i], i);
    }
}

int main()
{
    test();
}

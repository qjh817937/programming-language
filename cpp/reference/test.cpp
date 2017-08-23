#include<stdio.h>
#include<iostream>
using namespace std;
int b=3;

void test(void** p)
{
    *p = &b;
}

void test2(void*& p)
{
    p = &b;
}

int main()
{
    int* a = NULL;
    test((void**)&a);
    printf("a=%d\n",*a);
    
    int* c = NULL;
    void* d = c;
    test2((void*)d);
    printf("c=%d\n",*d);

    return 0;
}

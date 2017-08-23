#include<stdio.h>
#include<iostream>
#include<sstream>
using namespace std;

int main()
{
    char c = 0x01;
    printf("%c\n",c);
    printf("%c\n",0x01);
    stringstream ss;
    ss << c;
    ss << char(0x01);
    cout << ss.str() << endl;

    return 0;
}

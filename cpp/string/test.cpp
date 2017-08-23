#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

static string rmfrontsubstr(const string& str, const string& sub)
{   
    if(str.find(sub) != string::npos)
    {   
        return str.substr(sub.size());
    }   
    return str;
}  

//
// 用gdb调试时,在test函数中 无法打印s1, 可以打印s2
//
//
void test(string s1, string& s2)
{
    printf("%s\n", s1.c_str());
    printf("%s\n", s2.c_str());
}

int main()
{
    string str = "aaa\0bbb";
    string str2 = "ccc\0eee";
    cout << str << endl;
    cout << str2 << endl;

    cout << str2.substr(str2.size()) << endl;
    /*
    string str = "aaa\0bbb";
    test(str, str);
       str[3] = 0;

       cout << str << endl;
       printf("%s\n",str.c_str());
       printf("%.*s\n",str.size(), str.c_str());
       printf("%.*s\n",str.size(), str.data());

       printf("%d\n",str.size());

       cout << rmfrontsubstr("aaaa/bbb/ccc/", "aaa");
       */
    return 0;
}

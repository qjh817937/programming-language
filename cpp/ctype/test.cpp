#include<ctype.h>
#include<iostream>
using namespace std;

int main()
{
    string str = "adkslfa12343";
    for(size_t i = 0; i < str.size(); i++)
    {
        cout << str[i] << ":" << isdigit(str[i]) << endl;
    }

    return 0;
}

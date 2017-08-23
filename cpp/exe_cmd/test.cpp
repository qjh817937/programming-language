#include<stdio.h>
#include<iostream>
using namespace std;
string getCmdResult(const string& cmd)
{   
    string result;

    FILE *fpRead;
    fpRead = popen(cmd.c_str(), "r");
    char buf[1024];
    memset(buf,'\0',sizeof(buf));
    while(fgets(buf,1024-1,fpRead)!=NULL)
    {   
        result += buf;
    }   
    if(fpRead!=NULL)
        pclose(fpRead);
    return result;
}

int main()   
{
    string result = getCmdResult("ls *xx");
    cout << "exe cmd finish" << endl;
    cout << "result is:" << result;
}

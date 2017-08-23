#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

int getFileStat(string path, struct stat& st) 
{   
    if(stat(path.c_str(), &st)!=0)
    {   
        printf("get file[%s] stat failed", path.c_str());
        return -1;
    }   
    return 0;
}   

void isDir(string path)
{
    struct stat st;
    getFileStat(path, st);
    if(S_ISDIR(st.st_mode))
    {
        printf("%s is dir\n", path.c_str());
    }
    else
    {
        printf("%s is not dir\n", path.c_str());
    }
}


int main()
{
    isDir("/");
    isDir("/home/jianshen");
    isDir("/home/jianshen/");
    isDir("/home/jianshen/t.sh");
    isDir("/home/jianshen//t.sh");
    return 0;
}

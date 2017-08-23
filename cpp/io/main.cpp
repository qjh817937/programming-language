#include<iostream>
#include<fstream>
using namespace std;

char fileName[10] = "data.txt";

//读取方式: 逐行读取, 将行读入字符串, 行之间用回车换行区分
//If you want to avoid reading into character arrays, 
//you can use the C++ string getline() function to read lines into strings
void ReadDataFromFileIntoString()
{
    ifstream fin(fileName);  

    if(!fin.is_open())
    {
        cout << "open failed" << endl;
        return ;
    }
    
    string s;  
    while( getline(fin,s) )
    {    
        cout << "Read from file: " << s << endl; 
    }
    fin.close();
}

void ReadDataFromFileIntoCharArray()
{
    #define KEYWORD_MAX_LEN 5
    char buf[KEYWORD_MAX_LEN];

    ifstream ifs(fileName);
    if (ifs.fail())
    {
        cout << "open failed" << endl;
        return ;
    }

    while (!ifs.eof())
    {
        if(ifs.getline(buf, KEYWORD_MAX_LEN).good())
        {
            cout << buf << endl;
        }
        else
        {
            cout << "read error" << endl;
        }
    }
}

int main()
{
    ReadDataFromFileIntoString();
    ReadDataFromFileIntoCharArray();
    return 0;
}

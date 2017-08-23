#include<iostream>
#include<string>
#include<vector>
#include<sys/time.h>
using namespace std;

#define NUM 5000000

//string s = "aaabbbcccdddeeefffggghhhiii";
string s = "aaabbbccc";
string t = "";

//清除头尾的space,tab字符
std::string& trim(std::string& str)
{
    std::string::size_type p = str.find_first_not_of(" \t\r\n");
    if (p == std::string::npos)
    {
        str = "";
        return str;
    }
    std::string::size_type q = str.find_last_not_of(" \t\r\n");
    str = str.substr(p, q-p+1);
    return str;
}

void split3(std::vector<std::string>& vs,
    const std::string& line,
    char dmt)
{
    std::string::size_type p = 0;
    std::string::size_type q;
    vs.clear();
    for(;;)
    {
        q = line.find(dmt, p);
        std::string str = line.substr(p, q - p);
        trim(str);
        vs.push_back(str);
        if(q == std::string::npos)
        {
            break;
        }
        p = q + 1;
    }
}

void test_find()
{
    for(int i = 0; i < NUM; i++)
    {
        size_t last_pos = 0, now_pos = 0;
        while(true)
        {  
            now_pos = s.find('', last_pos);
            t = s.substr(last_pos, now_pos - last_pos);
            if(now_pos == string::npos)
            {
                break;
            }
            last_pos = now_pos +1;
        }       
    }
}

void test_split()
{
    vector<string> vs;
    char dmt = '';
    for(int i = 0; i < NUM; i++)
    {
        std::string::size_type p = 0;
        std::string::size_type q;
        vs.clear();
        for(;;)
        {
            q = s.find(dmt, p);
            std::string str = s.substr(p, q - p);
            trim(str);
            vs.push_back(str);
            if(q == std::string::npos)
            {
                break;
            }
            p = q + 1;
        }
        //    split3(vs, s, '');

        for(int j = 0; j < vs.size(); j++)
        {
            t = vs[j];
        }
    }
}

int main()
{
    /*
    timeval tv_start,tv_end;

    gettimeofday(&tv_start,NULL);
    test_find();
    gettimeofday(&tv_end,NULL);
    printf("%d\n", 1000000 * (tv_end.tv_sec - tv_start.tv_sec) + (tv_end.tv_usec - tv_start.tv_usec));

    gettimeofday(&tv_start,NULL);
    test_split();
    gettimeofday(&tv_end,NULL);
    printf("%d\n", 1000000 * (tv_end.tv_sec - tv_start.tv_sec) + (tv_end.tv_usec - tv_start.tv_usec));
    */

       string a = "111bbbba";
       //size_t pos = a.find('a', 2);
       //cout << "pos=" << pos << "sub=" << a.substr(pos) << endl;

       //size_t last_pos = pos+1;
       //pos = a.find('a', last_pos);
       cout << "sub=" << a.substr(8,10) << endl;
       cout << "sub=" << a.substr(9,10) << endl;
    /*
       pos = a.find('a', 13);
       cout << "pos=" << pos << endl;
       cout << "npos=" << string::npos << endl;
       cout << "sub=" << a.substr(pos) << endl;
       */
    /*
       string a = "slfjasfaslfk";
       size_t p = a.find_first_of('a');
       cout << p << a.substr(0,p)  << endl;
       cout << p+1 << a.substr(p+1)  << endl;
       p = a.find_first_of('a',p);
       cout << p << a.substr(0,p)  << endl;
       p = a.find_first_of('a',p+1);
       cout << p << a.substr(0,p)  << endl;

       p = a.find_first_of('k');
       cout << p << endl;
       p = a.find_first_of('k',p+1);
       if(string::npos == p)
       {
       cout << "npos" << endl;
       }
       else
       {
       cout << p << endl;
       }
       */
    return 0;
}

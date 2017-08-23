#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<sys/time.h>
using namespace std;

#define NUM 5000000

list<string> l;

void test_frontplusplus()
{
    for(int i = 0; i < NUM; i++)
    {
        for(list<string>::iterator iter = l.begin();
            iter != l.end();
            ++iter)
        {
            
        }
    }
}

void test_endplusplus()
{
    for(int i = 0; i < NUM; i++)
    {
        for(list<string>::iterator iter = l.begin();
            iter != l.end();
            iter++)
        {
            
        }
    }

}

int main()
{
    l.assign(50, "abc");

    timeval tv_start,tv_end;

    gettimeofday(&tv_start,NULL);
    test_frontplusplus();
    gettimeofday(&tv_end,NULL);
    printf("%d\n", 1000000 * (tv_end.tv_sec - tv_start.tv_sec) + (tv_end.tv_usec - tv_start.tv_usec));

    gettimeofday(&tv_start,NULL);
    test_endplusplus();
    gettimeofday(&tv_end,NULL);
    printf("%d\n", 1000000 * (tv_end.tv_sec - tv_start.tv_sec) + (tv_end.tv_usec - tv_start.tv_usec));

    return 0;
}

#include "stdio.h"
#include "fstream"
using namespace std;

int main(int arrc, char **argv)
{
    string strOutputFile = argv[1];
    string str = argv[2];
    ofstream ofs(strOutputFile.c_str());
    for(int i = 0; i < 100000000; i++)
    {
        ofs << str << endl;
    }
    ofs.close();

    return 0;
}

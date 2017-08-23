#include "stdio.h"

FILE *pFile;

void test(int argv)
{
    int i = argv;
    char *p = (char*) &i;
    fwrite(p, sizeof(char), 4, pFile);
    for(int i = 0; i < 4;i++)
    {
        printf("%d\n", p[i]);
    }
}

int main()
{
    pFile = fopen("data", "w");
    test(1);
    test(280);
   return 0;
}

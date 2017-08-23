#include <stdio.h>

int main()
{
    int i = 0x12345678;
    char *p = (char*)&i;
    if(p[0] == 0x12)
    {
        printf("big endian\n");
    }
    else
    {
        printf("small endian\n");
    }

    for(int j = 0; j < 4; j++)
    {
        printf("%d:%x\n", j, p[j]);
    }
    return 0;
}

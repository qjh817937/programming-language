#include<stdio.h>
#include<assert.h>

int main()
{
    printf("1\n");
    assert(0 == 0);
    printf("2\n");
    assert(0 == 1);
    printf("3\n");
    return 0;
}

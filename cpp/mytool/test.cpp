#include "byte_stream.h"

int main()
{
    ByteStream bs;
    char c = 'E';
    bs.write(c);
    bs.write('a');

    FILE *pFile = fopen("data","w");
    fwrite(bs.data(), sizeof(char), bs.size(), pFile);
    return 0;
}


/*
void test()
{
#define READ_CONFIG(VARIABLES_NAME, SECTION, KEY, DEFAULT_VALUE) \
    const char * VARIABLES_NAME = config.get_string(SECTION,KEY,DEFAULT_VALUE); \
    if(NULL == VARIABLES_NAME || '\0' == VARIABLES_NAME[0]) \
    { \
        Log_r::Error("[BuildCache::init] get config["); \
    }


    READ_CONFIG(sQueryFile, queryName.c_str(), "query_file", "./query.gbk.txt");
}
*/

#include <stdio.h>
#define debug_msg(fmt, args ...) printf("%s[%d]:"fmt, __FILE__, __LINE__,##args)

int main()
{
        debug_msg("%s, %d", "test", 1);
        return 0;
}


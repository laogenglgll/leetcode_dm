/*
就加了一个判断语句，结构时间减少一半。。。。。。。。。。
O()
O()
*/

#include <stdio.h>
#include <string.h>

int main()
{
   
   return 0;
}

int strStr(char * haystack, char * needle){
    int i = 0,j = 0;
    int haystacklong = strlen(haystack);
    int needlelong = strlen(needle);
    if(needlelong == 0) return 0;
    for(i = 0;i < haystacklong;i++)
    {
        for(j = 0;j < needlelong;j++)
        {
            if(haystack[i + j] != needle[j])break;
        }
        if(j == needlelong - 1) return i;
    }
    return -1;
}


/*
int strStr(char * haystack, char * needle){
    int i = 0,j = 0;
    int haystacklong = strlen(haystack);
    int needlelong = strlen(needle);
    if(needlelong == 0) return 0;
    for(i = 0;i < haystacklong;i++)
    {
        if(i > (haystacklong - needlelong)) return -1;
        for(j = 0;j < needlelong;j++)
        {
            if(haystack[i + j] != needle[j])break;
        }
        //printf("%d",i);
        if(j == needlelong) return i;
    }
    return -1;
}
*/

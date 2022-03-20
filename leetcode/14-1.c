/*

O()
O()
*/

#include <stdio.h>
#include <string.h>

int main()
{
   char * longestCommonPrefix(char ** strs, int strsSize);
   char d[2][10] = {"ab","a"};
   char *b[2] = {d[0],d[1]};
   char * r = {"ab","a"};  //不行
   printf("%s\n",* (r + 1));
   //char * a  = d;
   char **e = b;
   char * re;
   re = longestCommonPrefix(e,2);
   printf("%s\n",re);
   return 0;
}

char * longestCommonPrefix(char ** strs, int strsSize)
{
    if(strsSize == 0) return "";
    static char str[20] ;
    strcpy(str,((* (strs + 0))));
    int i = 0,j = 0;
    for(i = 1;i<strsSize;i++)
    {
        for(j = 0;j < strlen(* (strs + i));j++)
        {
            printf("%c\n",(* (strs + i))[j]);
            if(str[j] != ((* (strs + i))[j]) || j >= strlen(str)) { break;}
        }
        str[j] = '\0';
    }
    return str;
}

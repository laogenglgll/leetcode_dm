/*
虽然我看错题了，但这丝毫不影响我是个sb。
strlen(* strs) ，测量长度
我失败了，我也不想改了，简直就是个失败。。。。。
int (*a)[N] 指向一个长度为N的数组  sy-14
int * a[N] 指针数组
？函数返回时，直接返回字符数组变量名警告，用char * 没事 ，不知道为什么经过中间的转换。
O() 鬼知道我写的什么，反正我看看不懂了。
O()
*/

#include <stdio.h>
#include <string.h>

int main()
{
   char * longestCommonPrefix(char ** strs, int strsSize);
   char d[3][10] = {"flower","flow","flight"};
   char *b[3] = {d[0],d[1],d[2]};
   //char * a  = d;
   char **e = b;
   printf("%c",*(longestCommonPrefix(e,3) + 1));
   return 0;
}

char * longestCommonPrefix(char ** strs, int strsSize)
{
    if(strsSize == 0) return "";
    char t[3][2] ;
    int sum[4],i = 0,j = 0,xb = 0;
    memset(sum,0,sizeof(sum));
    int longer = 0;
    for(i = 0;i < strsSize;i++)
    {
        longer = (strlen(* strs) >=2)? 2:(strlen(* strs)); 
        for(j = 0;j < longer;j++)
        {
            t[i][j] = strs[i][j];
        }
    }
    for(i = 0;i < strsSize;i++)
    {
        for( j = i + 1;j < strsSize;j++)
        {
            if(t[i][0] == t[j][0] && t[i][1] == t[j][1]) sum[i]++;
        }
    }
    j = 0;
    for(i = 0;i < strsSize;i++)
    {
       if(sum[i] >= j) j = sum[i],xb = i;
    }
    if(sum[xb] == 0) return "";
    char q[3];
    q[0] = t [xb][0],q[1] = t[xb][1],q[2] = '\0';
    char *re = q; 
    return re;
}

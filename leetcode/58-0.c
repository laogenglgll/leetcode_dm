/*
s ！=NULL 的条件。。。。。。。
再次见到了我的愚蠢，见到官方的我感觉我的大脑已经固定思维了，想改变下大脑。。。。。
O()
O()
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "   fly me   to   the moon  ";
    lengthOfLastWord(a); 
   return 0;
}


int lengthOfLastWord(char * s){
    int num = 0;
    int max = 0;
    while(strlen(s)) //不能使用 s ！=NULL 作为条件 ，因为他为空的时候有地址，只是没有值或值对不上，
    {
        if(*(s) == ' ') num = 0;
        else num += 1;
        s = s + 1;
        if( num > 0) max = num;
    }
    return max;
}

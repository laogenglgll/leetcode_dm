/*
数组回文
O(N)
O(1);
*/

#include<stdio.h>

int main()
{
    int isPalindrome(int x);
    int bools = 0;
    bools = isPalindrome(121);

}

int  isPalindrome(int x){
    int a[10] = {0},count = 0,number = 0,i = 0;
    while(x)
    {
        number = x % 10;
        x = x / 10;
        a[count++] = number;
    }
    for(i = 0;i<count - 1;i++)
    {
        if(a[i]!=a[count-1]) return 1; //count 忘记减一了
        count --;
    }
    return 0;
}
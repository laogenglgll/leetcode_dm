/*
数组分支选择
O(N)
O(1)
*/
#include<stdio.h>
#include<string.h>

int main()
{
    int romanToInt(char * s);
    char a[100] = "MCMXCIV";
    romanToInt(a);
}

int romanToInt(char * s)
{
    int sum = 0,i = 0;
    char t;
    //int n = strlen(s);
    for(i = 0;i < strlen(s);i++)
    {
        t = *(s + i);
        switch (t)
        {
        case 'I'/* constant-expression */:if(*(s + i + 1) == 'V') sum += 4,i++ ;else if(*(s + i + 1 ) == 'X') sum += 9,i++;else sum += 1;
            /* code */
            break;
        case 'V' : sum += 5;break;
        case 'X' :if(*(s + i + 1) == 'L') sum += 40,i++ ;else if(*(s + i + 1 ) == 'C') sum += 90,i++;else sum += 10;break;
        case 'L' : sum += 50;break;
        case 'C' :if(*(s + i + 1) == 'D') sum += 400 ,i++;else if(*(s + i + 1 ) == 'M') sum += 900,i++;else sum += 100;break;
        case 'D' : sum += 500;break;
        case 'M' :sum += 1000;break;
        default: printf("大傻逼你弄错了");return 1;
            break;
        }
    }
    return sum;
}
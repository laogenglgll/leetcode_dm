/*
char 数组多加一个位置，'\0';
O()
O()
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char * addBinary(char * a, char * b);
    char a[] = "110010",b[] = "100";
    addBinary(a,b);
    return 0;
}


char * addBinary(char * a, char * b) {
    int aLong = strlen(a) ,bLong = strlen(b);
    int sum = 0;
    int n = fmax(aLong,bLong);
    int cLong = 0;
    int* c = (int*)malloc(sizeof(int) * (n + 1));
    memset(c,0,sizeof(int) * (n + 1));
    while(aLong != 0 || bLong != 0) {
        sum += (aLong ? (a[aLong-- - 1] == '1') : 0);
        sum += (bLong ? (b[bLong-- - 1] == '1') : 0);
        switch (sum) {
        case 0/* constant-expression */:c[cLong++] = 0;break;
        case 1:c[cLong++] = 1;break;
        case 2:c[cLong++] = 0,c[cLong] = 1;break;
        case 3:c[cLong++] = 1,c[cLong] = 1;break;
        default:printf("你是大傻逼");break;
        }
        sum = sum / 2;
    }
    /*
    while (aLong) {
        sum = c[cLong] + (int)a[aLong - 1] - 48;
        aLong--;
        switch (sum) {
        case 0:c[cLong++] = 0;break;
        case 1:c[cLong++] = 1;break;
        case 2:c[cLong++] = 0,c[cLong] = 1;break;
        }
    }
    while (bLong) {
        sum = c[cLong] + (int)b[bLong - 1]- 48;
        bLong--;
        switch (sum) {
        case 0:c[cLong++] = 0;break;
        case 1:c[cLong++] = 1;break;
        case 2:c[cLong++] = 0,c[cLong] = 1;break;
        }
    }
    */
    char* returnC = (char *)malloc(sizeof(int) * (cLong + 2));
    int i = 0;
    printf("%d\n",c[cLong]);
    if(c[cLong] == 0) cLong--;
    while(cLong >= 0) {
        returnC[i++] = c[cLong--] + 48;
    }
    returnC[i] = '\0';
   return returnC; 
}
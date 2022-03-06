/*

O()
O()
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int* plusOne(int* digits, int digitsSize, int* returnSize);
    int a[] = {9,9};
    int c;
    int * re;
    re = plusOne(a,2,&c);
    printf("%d",re[1]);
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int beforeSum = 0,nowNumber = 0;
    int i = 0;
    beforeSum = digits[digitsSize - 1] + 1;
    if(beforeSum >= 10){
        digits[digitsSize - 1] = 0;
        beforeSum = 1;
        i++;
    }
    else{
        digits[digitsSize - 1] = digits[digitsSize - 1] + 1;
        beforeSum = 0;
    }
    while(beforeSum != 0 && i < digitsSize)
    {
        if(beforeSum + digits[digitsSize - 1 - i] >= 10){
            digits[digitsSize - 1 - i] = 0;
            beforeSum = 1;
        }
        else{
            digits[digitsSize - 1 - i] = digits[digitsSize - 1 - i] + beforeSum;
            beforeSum = 0;
        }
        i++;
    }
    if(beforeSum == 0) i = digitsSize;
    else i = digitsSize + 1;
    int * re = (int *)malloc(sizeof(int) * i),j = 0;
    if(beforeSum != 0){
        re[j++] = beforeSum;
        while(j < i) re[j++] = digits[j - 1];
    }
    else memcpy(re,digits,sizeof(int) * i);
    return re;
}
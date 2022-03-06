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
    int returnSize;
    int * re;
    re = plusOne(a,2,&returnSize);
    printf("%d",re[1]);
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int beforeSum = 1,i = 0;
    while(beforeSum != 0 && i < digitsSize){
        if(digits[digitsSize - 1 - i] == 9){
            digits[digitsSize - 1 - i] = 0;
            beforeSum = 1;
        }
        else{
            digits[digitsSize - 1 - i] = digits[digitsSize - 1 - i] + beforeSum;
            beforeSum = 0;
        }
        i++;
    }
    * returnSize = digitsSize + beforeSum;
    int * re = (int *)malloc(sizeof(int) * (* returnSize)),j = 0;
    if(beforeSum == 1){
        re[j++] = beforeSum;
        memcpy(re + 1,digits,sizeof(int) * digitsSize);
    }
    else{
        memcpy(re,digits,sizeof(int) * i);
    }
    return re;
}


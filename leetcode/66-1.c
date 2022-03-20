/*
-0的原版，因为我感觉我十分的sb，受不了了。。。。。。。所以把-0优化了
O()
O()
*/

#include <stdio.h>
#include <string.h>

int main()
{
    return 0;
}

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
    if(beforeSum == 0) * returnSize =  i = digitsSize;
    else * returnSize =  i = digitsSize + 1;
    int * re = (int *)malloc(sizeof(int) * i);
    int j = 0;
    if(beforeSum != 0){
        re[j] = beforeSum;
        j++;
        while(j < i){
            re[j] = digits[j - 1];
            j++;
        } 
    }
    else{
        while(j < i)
        {
            re[j] = digits[j];
            j++;
        }
    }
    return re;
}
    
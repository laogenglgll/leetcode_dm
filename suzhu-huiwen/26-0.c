/*
官方评论下的jeason的解题思路;
突然感觉自己无论开什么题都看的太快了，没完全看懂就想解题去。。。。。。。。。。。
以后多看看题；
O()
O()
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int removeDuplicates(int* nums, int numsSize);
   int a[] = {1,2,3,4,4,4,5,5,6,6,6,6,7};
   removeDuplicates(a,13);
   return 0;
}

int removeDuplicates(int* nums, int numsSize){
    int index = 0 , i = 0;
    if(numsSize == 0) return numsSize;
    nums[index++] = nums[i++];
    while(i < numsSize)
    {
        if(nums[i] != nums[i - 1]) nums[index++] = nums[i];
        i++;
    }
    return index;
}
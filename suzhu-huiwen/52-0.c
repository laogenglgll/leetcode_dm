/*

O()
O()
*/

#include <stdio.h>
#include <string.h>

int main()
{
   int maxSubArray(int* nums, int numsSize);
   int a[] ={-2,1,-3,4,-1,2,1,-5,4};
   printf("%d\n",maxSubArray(a,9));
   return 0;
}

int maxSubArray(int* nums, int numsSize){
    //int 你妹的 = 4;
    //printf("%d\n",你妹的);
    int zhiqianhe = 0,dangqinhe = 0,zuidahe = -11000;
    //int nums_long = strlen( nums);
    int i = 0;
    while(i < 9)
    {
        if(zhiqianhe > 0)
        {
            dangqinhe = zhiqianhe + nums[i];
            zhiqianhe = dangqinhe;
        }
        else
        {
            dangqinhe = nums[i];
            zhiqianhe = dangqinhe;
        }
        if(dangqinhe > zuidahe)
        {
            zuidahe = dangqinhe;
        }
        i++;
    }
    return zuidahe;
}

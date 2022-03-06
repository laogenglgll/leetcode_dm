/*
二分查找
看网上的用递归玩玩，用递归条件多我要疯了。。。。

O()
O()
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int BinarySearch(int target, int start, int end,int * nums);
    int searchInsert(int* nums, int numsSize, int target);
    int a[] = {3,5,7,9,10};
    searchInsert(a,5,8);
    return 0;
}

int searchInsert(int* nums, int numsSize, int target){
    if(nums == NULL) return -1;
    int re =BinarySearch(target,0,numsSize - 1,nums);
    return re;
}

int BinarySearch(int target, int start, int end,int * nums)
{
    if(start > end) return start;
    int mid = (start + end) / 2;
    if(nums[mid] == target) return mid;
    else if(start == mid && mid == end)
    {
        if(nums[mid] < target) return mid + 1;
        else if(mid == 0) return 0;
        else return mid;
    }
    else if(nums[mid] < target) return BinarySearch(target,mid + 1,end,nums);
    else 
    {
        if(mid == 0) return 0;
        else return BinarySearch(target,start,mid - 1,nums);
    }
    /*
    1 2 5 6 
    3
    0 3  0 3
    1    1
    3     2 3
    0 0
    */
}

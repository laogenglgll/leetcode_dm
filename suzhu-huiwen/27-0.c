/*

O()
O()
*/

#include <stdio.h>
#include <string.h>

int main()
{
   
   return 0;
}

int removeElement(int* nums, int numsSize, int val){
    int numslong = 0;
    int i = 0;
    while (i < numsSize/* condition */)
    {
        if(*(nums + i) != val)
        {
            *(nums + numslong) = *(nums + i);
            numslong ++;
        }
        i ++;
        /* code */
    }
    return numslong; 
}
/*

O()
O()
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
   bool isOneBitCharacter(int* bits, int bitsSize);
   int a[] = {1,1,0};
   isOneBitCharacter(a,3);
   return 0;
}


bool isOneBitCharacter(int* bits, int bitsSize){
    if(bitsSize == 0 || bitsSize == 1 ) return true;
    if(bitsSize >= 3)
    {
        if (bits[bitsSize - 1] == 0 && bits[bitsSize - 2] == 1 && bits[bitsSize - 3] == 0) return false;
        }
    if(bitsSize > 1)
    {
        if(bits[bitsSize - 1] == 0 && bits[bitsSize - 2] == 0) return true;
    }
    
    if(bits[bitsSize - 1] == 0 && bits[bitsSize - 2] == 1) 
    {
        int i = 0,p = 0;
        while(i < bitsSize)
        {
            if(bits[i] == 1) i+=2,p = 0;
            else i+=1, p = 1;
        }
        if(p == 1) return true;
    }
    return false;
}
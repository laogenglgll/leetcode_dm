/*

O()
O()
*/

#include <stdio.h>
#include <string.h>

int main()
{
   char * pushDominoes(char * dominoes);
   return 0;
}

char * pushDominoes(char * dominoes){
   int longer = strlen(dominoes),i = 0;
   char left = 'L';
   while(i < longer)
   {
      int j = i;
      while(j < longer && dominoes[j] == '.')
      {
         j++;
      }
      char right = j < longer ? dominoes[j] : 'R';
      if(left == right)
      while(i < j)
      {
         dominoes[i] = right;
         i++;
      }
      else if(left == 'R' && right == 'L')
      while (i < j)
      {
         /* code */
         dominoes[i++] = 'R';
         dominoes[j--] = 'L';
      }
      right = left;
      i = j + 1;
   }
   return dominoes;
}

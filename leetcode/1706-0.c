/*

O()
O()
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int* findBall(int** grid, int gridSize, int* gridColSize, int* returnSize);
    int a[5][5] = {1,1,1,-1,-1,1,1,1,-1,-1,-1,-1,-1,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1};
    int * b,**d;
    b = &a;
    d = &b;
    int re[5];
    int * ret = re;
    int e = 5;
    findBall(d,5,&e,ret);
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findBall(int** grid, int gridSize, int* gridColSize, int* returnSize){
    int i = 0,j = 0,n = 0;
    int * ret = (int *) malloc(sizeof(int) * (* gridColSize));
    printf("%d\n",*(((*grid)+1)+1));
    for(n = 0;n < * gridColSize;n++)
    {
        j = n;
        ret[n] = 1;
        for(i = 0;i < gridSize;i++)
        {
            if(j == 0)
            {
                if(grid[i][j] == -1) {ret[n] = -1;break;}
            }
            else if(j == * gridColSize - 1)
            {
                if(grid[i][j] == 1) {ret[n] = -1;break;}
            }
            else if(grid[i][j] == 1 && grid[i][j + 1] == -1) {ret[n] = -1;break;}
            else if(grid[i][j] == -1 && grid[i][j - 1] == 1) {ret[n] = -1;break;}
        }
    }
    return ret;
}

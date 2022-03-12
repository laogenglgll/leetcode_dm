/*
..............clock..........
O()
O()
*/

#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    double headTime = 0,endTime = 0;
    headTime = clock();
    int climbStairs(int n);
    printf("%d\n",climbStairs(10));
    endTime = clock();
    printf("%.19lf\n",headTime - endTime);
    return 0;
}

int climbStairs(int n) {
    int i = 0,sum = 0;
    int q = 0, p = 1;
    for(i = 0;i < n;i++) {
        sum = q + p;
        q = p;
        p = sum;
    }
    return sum;
}
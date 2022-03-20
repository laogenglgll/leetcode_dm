/*

O()
O()
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int climbStairs(int n);
    int a = climbStairs(3);
    return 0;
}

int climbStairs(int n) {
    int* t = (int*)malloc(sizeof(int) * (n + 1));
    memset(t,0,sizeof(int) * (n + 1));
    int climbStairs_dg(int n,int* t);
    return climbStairs_dg(n,t);
}
int sum;

int climbStairs_dg(int n,int* t) {
    if(n == 1) return 1;
    else if(n == 2) return 2;
    else {
        if(*(t + n) != 0) {
            return t[n];
        }
        else {
            t[n] = climbStairs_dg(n - 1,t) + climbStairs_dg(n - 2,t);
        }
    }
    return t[n];
}
    
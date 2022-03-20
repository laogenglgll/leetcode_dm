/*

O()
O()
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int mySqrt(int x);
    printf("%d\n",mySqrt(2147395599));
    return 0;
}

int mySqrt(int x){
    double EPSINON = 0.000001;
	double low = 0.0;
	double high = x;
	double mid = (low + high) / 2;
	while ((high - low) > EPSINON) {
		if (mid*mid > x) {
			high = mid;
		}
		else{
			low = mid;
		}
		mid = (high + low) / 2;
	}
    if(x == 1) return 1;
	if(mid < x)
    	mid += 0.00001; 
	return mid;
}
    
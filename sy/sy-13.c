
#include<stdio.h>

int main()
{
    char a = 'a';
    switch (a)
    {
    case 'a'/* constant-expression */: if(a == 'c')printf("p");else printf("n");
        /* code */
        break;
    
    default:
        break;
    }
}
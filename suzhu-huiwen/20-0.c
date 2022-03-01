/*
C 语言变量空间全是刚开始时分配的，所以不能用变量定义数组，用malloc
O()
O()
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main()
{
   bool isValid(char * s);
   char a[] = "()";
   if(isValid(a)) printf("true \n");
   else printf("false \n");
   return 0;
}

bool isValid(char * s){
    int longer = strlen(s);
    char S[1000 + 10];
    int i = 0;
    S[0] = '\0';
    char t = 'a';
    while( * s != '\0')
    {
        t = * s;
        s++;
        if(i == 0 && (t == ']' || t == '}' || t == ')')) return false;
        switch (t)
        {
        case ']'/* constant-expression */: if(S[i - 1] == '[') i--; else return false ;
            /* code */
            break;
        case '}' : if(S[i - 1] == '{') i--;else return false ;break;
        case ')' : if(S[i - 1] == '(') i--;else return false ; break;
        
        default: S[i] = t;S[i + 1] = '\0';i++;
            break;
        }  
        
    }
    if(i != 0) return false;
    return true;
}

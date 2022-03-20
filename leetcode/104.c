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

int maxDepth(struct TreeNode* root){
    int sum = 0;
    sum = maxDEpth(root,sum);
    return sum;
}

int maxDEpth_1(struct TreeNode* root,int sum) {
    if(root == NULL) {
        return sum;
    }
    sum++;
    int t1 = 0,t2 = 0;
    t1 = maxDEpth(root->left,sum); 
    t2 = maxDEpth(root->right,sum;
    sum = (t1 > t2) ? t1 : t2;
    return sum;
}
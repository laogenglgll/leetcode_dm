/*

O()
O()
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    return 0;
}


struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

bool isSame(struct TreeNode* p,struct TreeNode* q) {
    if(p == NULL && q ==NULL) {
        return true;
    }
    else if(p == NULL || q == NULL) {
        return false;
    }
    else if(p->val != q->val) return false;
    return (isSame(p->left,q->right) && isSame(p->right,q->left));
}

bool isSymmetric(struct TreeNode* root){
    return isSame(root->left,root->right);
}
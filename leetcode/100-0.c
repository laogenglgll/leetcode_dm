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
    else if(q == NULL || p == NULL) {
        return false;
    }
    if(p->val != q->val) return false;
    return (isSame(p->left,q->left) && isSame(p->right,q->right));
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    return isSame(p,q);
}
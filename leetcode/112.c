/*
官方的再次说明我狗屁不是。。。。
O()
O()
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
};

int main()
{
    return 0;
}


bool hasPathSum(struct TreeNode *root, int sum) {
    if (root == NULL) {
        return false;
    }
    if (root->left == NULL && root->right == NULL) {
        return sum == root->val;
    }
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
}


/*

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int targetSum){
    if(root == NULL) {
        return false;
    }
    if(roo->left == NULL & root->right == NULL && root->val == targetSum) {
        return true;
    }
    int hasPathsum (struct TreeNode* root,int targetSum,int sum);
    if(hasPathsum(root->left,targetSum,root->val) == targetSum ) {
        return true;
    }
    if(hasPathsum(root->right,targetSum,root->val) == targetSum ) {
        return true;
    }
    return false;
}

int hasPathsum (struct TreeNode* root,int targetSum,int sum) {
    if(root == NULL) {
        return sum;
    }
    sum += root->val;
    if(sum == targetSum) {
        return sum;
    } else if(sum > targetSum) {
        return sum - root->val;
    } else {
        int n1 = hasPathsum(root->left,targetSum,sum);
        if(n1 == targetSum) return n1;
        int n2 = hasPathsum(root->right,targetSum,sum);
        if(n2 == targetSum) return n2;
    }
    return sum - root->val;
}
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
int hasPathsum (struct TreeNode* root,int targetSum,int sum);

bool hasPathSum(struct TreeNode* root, int targetSum){
    hasPathSum(root,targetSum,root->val);
}

int hasPathsum (struct TreeNode* root,int targetSum,int sum) {
    
}


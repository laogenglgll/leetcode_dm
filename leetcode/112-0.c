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
    bool hasPathSum(struct TreeNode* root, int targetSum);
    int a[] = {5,4,8,11,null,13,4,7,2,null,null,null,1},
    hasPathSum()
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
int haspathsum1 (struct TreeNode* root,int targetSum,int sum);
    return haspathsum1(root,targetSum,0);
    

}

int haspathsum1 (struct TreeNode* root,int targetSum,int sum) {
    if(root == NULL) {
        return false;
    }
    if (root->left == NULL && root->right == NULL) {
        return targetSum == sum;
    }
    return haspathsum1(root->left,targetSum,sum + root->val) || haspathsum1(root->right,targetSum,sum + root->val);
}

//判断a是否等于 0
void s1(int a) {
    if (a == 0) {
        printf("true");
    } else {
        printf("false");
    }
}

//快速排序
void skuait (int* a) {
    int i,j,temp;
    i = 0;
    j = 0;
    temp = 0;
    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}


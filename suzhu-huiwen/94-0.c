/*
事实证明必须是（*returnSize）++ 不能是*returnSize++;
看-1
O()
O()
*/

#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
    return 0;
}



 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 


/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode* root,int* re,int* returnSize) {
    if(root == NULL) {
        return;
    }
    inorder(root->left,re,returnSize);
    re[(*returnSize)++] = root->val;
    inorder(root->right,re,returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* re = (int*) malloc(sizeof(int) * 1001);
    * returnSize = 0;
    inorder(root,re,returnSize);
    return re;
}
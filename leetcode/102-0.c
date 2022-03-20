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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    * returnSize = 0;
    if(root == NULL) {
        return NULL;
    }
    int** res = (int**)malloc(sizeof(int*) * 2000);//可以写1000，示例最大竖直1000层左右。
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
    int head = 0,last = 0;
    struct TreeNode* queue[2000] = {};
    queue[last++] = root;
    struct TreeNode* ts = NULL;
    while(head != last) {
        int colSize = last - head,t = last;
        int* re = (int*)malloc(sizeof(int) * (colSize + 5));
        for(int j = 0;j < colSize;j++) {
            re[j] = queue[head]->val;
            if(queue[head]->left != NULL) {
                queue[last++] = queue[head]->left;
            } 
            if(queue[head]->right != NULL) {
                queue[last++] = queue[head]->right;
            } 
            head++;
        }
        (*returnColumnSizes)[*returnSize] = colSize;
        res[*returnSize] = re;
        (*returnSize)++;
    }
    return res;
}
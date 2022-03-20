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


struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

int a[6000] = {};

void HashTableInit(int* inorder,int* len) {
    for(int i = 0;i < *len;i++) {
        a[inorder[i] + 3000] = i;
    }
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    struct TreeNode* buildTree_1(int* preorder,int proLeft,int proRight,int* inorder,int inoLeft,int inoRight);
    HashTableInit(inorder,inorderSize);
    return buildTree_1(preorder,0,preorderSize,inorder,0,inorderSize);
}

struct TreeNode* buildTree_1(int* preorder,int proLeft,int proRight,int* inorder,int inoLeft,int inoRight) {
    if(proLeft > proRight || inoLeft > inoRight) {
        return NULL;
    }
    
    int rootVal = preorder[proLeft];
    struct TreeNoder* root = malloc(sizeof(struct TreeNode));
    int pIndex = a[rootVal];
    //递归关系官方导出来的。
    buildTree_1(preorder,proLeft + 1,pIndex - inoLeft + proLeft,inorder,inoLeft,pIndex - 1);
    buildTree_1(preorder,pIndex - inoLeft + proLeft + 1,proRight,inorder,pIndex + 1,inoRight);
    return root;
}
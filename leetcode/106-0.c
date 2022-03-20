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

int a[6001] = {};

void HashTableInit(int* inorder,int* len) {
    for(int i = 0;i < * len;i++) {
        a[inorder[i] + 3000] = i;
    }
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    struct TreeNode* buildTree_1(int* inorder,int inHead,int inLast,int* postorder,int poHead,int* poLast);
    void HashTableInit(int* inorder,int* len);
    HashTableInit(inorder,inorderSize);
    postorder -= 1;
    return buildTree_1(inorder,0,inorderSize - 1,postorder,0,&(postorderSize));
}

struct TreeNode* buildTree_1(int* inorder,int inHead,int inLast,int* postorder,int poHead,int* poLast) {
    if(inHead > inLast || poHead > (* poLast)) {
        return NULL;
    }
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    int rootVal = postorder[(* poLast)];
    (*poLast)--;
    root->val = rootVal;
    int inIndex = a[rootVal + 3000];
    root->right = buildTree_1(inorder,inIndex + 1,inLast,postorder,poHead,poLast);
    root->left = buildTree_1(inorder,inHead,inIndex - 1,postorder,poHead,poLast);
    return root;
}
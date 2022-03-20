/*  将有序数组转换为二叉搜索树
二叉搜索树的中序遍历是升序序列，题目给定的数组是按照升序排序的有序数组，因此可以确保数组是二叉搜索树的中序遍历序列。
O()
O()
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

int main()
{
    struct TreeNode* sortedArrayToBST_1(int* nums, int numsSize);
    int a[] = {1,2,3,4,5,6,7,8,9,0};
    sortedArrayToBST_1(a,10);
    return 0;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize ) {
    struct TreeNode* arrayToBST(int* nums,int head,int last);
    return arrayToBST(nums,0,numsSize - 1);
}

struct TreeNode* arrayToBST(int* nums,int head,int last) {
    if(head > last) {
        return NULL;
    }
    //取中间数作为节点的值
    int mid = (head + last) / 2;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    //分成左右数组，因为两个数组长度肯定相等或者差一，所以是高度平衡树
    root->left = arrayToBST(nums,head,mid - 1);
    root->right = arrayToBST(nums,mid + 1,last);
    return root;
}

/*
struct TreeNode* sortedArrayToBST_1(int* nums, int numsSize){
    struct TreeNode* a[2000],* b[2000];
    int ai = 0,bi = 0;
    int i = 0;        
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    struct TreeNode* rootHead = root;
    struct TreeNode* rootFather = NULL;
    root->val = nums[i++];
    a[ai++] = root;
    while(i < numsSize) {
        bi = 0;
        for(int j = 0;j < ai && i <numsSize;j++) {
            rootFather = a[j];
            root = malloc(sizeof(struct TreeNode));
            rootFather->left = root;
            root->val = nums[i++];
            b[bi++] = root;
            if(i <numsSize) {
                rootFather = a[j];
                root = malloc(sizeof(struct TreeNode));
                rootFather->right = root;
                root->val = nums[i++];
                b[bi++] = root;
            }
        }
        ai =0;
        for(int j = 0;i <numsSize && j < bi;j++) {
            rootFather = b[j];
            root = malloc(sizeof(struct TreeNode));
            rootFather->left = root;
            root->val = nums[i++];
            a[ai++] = root;
            if(j < bi && i <numsSize) {
                rootFather = b[j];
                root = malloc(sizeof(struct TreeNode));
                rootFather->right = root;
                root->val = nums[i++];
                a[ai++] = root;
            }
        }
    }
    return rootHead;
}
*/
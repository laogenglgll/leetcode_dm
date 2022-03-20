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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
int nums[2000] = {};

struct TreeNode* sortedListToBST(struct ListNode* head) {
    struct TreeNode* arrayToBST(int* nums,int head,int last);
    int  arrayTOBst(int* nums,struct ListNode* head);
    int len = arrayToBst(nums,head);
    return arrayToBST(nums,0,len - 1);
}

int arrayTOBst(int* nums,struct ListNode* head) {
    int len = 0;
    while(head != NULL) {
        nums[len++] = head->val;
        head = head->next;
    }
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
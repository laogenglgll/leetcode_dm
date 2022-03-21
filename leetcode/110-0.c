/*判断是否为平衡二叉树
我这个是逆的。。。
下面是快的，结果出来时还不知道为什么这么慢，跟预期不符。
O()
O()
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int main()
{
    struct TreeNode* treeNodeHead();
    bool isBalanced(struct TreeNode* root);
    struct TreeNode* head = NULL;
    head = treeNodeHead();
    isBalanced(head);
    return 0;
}

struct TreeNode* treeNodeHead() {
    int rootVal = 0;
    struct TreeNode* head =(struct TreeNode*) malloc(sizeof(struct TreeNode));
    scanf("%d",&rootVal);
    if(rootVal == -1) {
        head = NULL;
    } else {
        head->val =rootVal;
        head->left =  treeNodeHead(head);
        head->right = treeNodeHead(head);
    }
    return head;
}


bool isBalanced(struct TreeNode* root){
int maxDEpth(struct TreeNode* root,int sum);
    if(root == NULL) {
        return true;
    }
    int sum = 0;
    sum = maxDEpth(root,sum);
    return sum;
}

int maxDEpth(struct TreeNode* root,int sum) {
    if(root == NULL) {
        return sum;
    }
    sum++;
    int t1 = 0,t2 = 0;
    t1 = maxDEpth(root->left,sum); 
    t2 = maxDEpth(root->right,sum);
    if(t1 == false || t2 == false) {
        return false;
    }
    sum = (t1 > t2) ? t1 : t2;
    if( t1 - t2 >= 2 || t2 - t1 >= 2) {
        return false;
    }
    return sum;
}

/*
bool isBalanced(struct TreeNode* root){
int maxDEpth(struct TreeNode* root,int sum);
    if(root == NULL) {
        return true;
    }
    int sum = 0;
    sum = maxDEpth(root,sum);
    return sum;
}

int maxDEpth(struct TreeNode* root,int sum) {
    if(root == NULL) {
        return sum;
    }
    sum++;
    int t1 = 0,t2 = 0;
    t1 = maxDEpth(root->left,sum); 
    if(t1 == false) {
        return false;
    }
    t2 = maxDEpth(root->right,sum);
    if(t2 == false) {
        return false;
    }
    sum = (t1 > t2) ? t1 : t2;
    if( t1 - t2 >= 2 || t2 - t1 >= 2) {
        return false;
    }
    return sum;
}
*/
/*
int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        return fmax(height(root->left), height(root->right)) + 1;
    }
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    } else {
        return fabs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
}
//官方的。。。。。
*/
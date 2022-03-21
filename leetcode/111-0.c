/*二叉树的最小深度
官方的
O()
O()
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
};

int main()
{
    return 0;
}

int minDepth(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    int min_depth = INT_MAX;
    if (root->left != NULL) {
        min_depth = fmin(minDepth(root->left), min_depth);
    }
    if (root->right != NULL) {
        min_depth = fmin(minDepth(root->right), min_depth);
    }

    return min_depth + 1;
}



typedef struct {
    int val;
    struct TreeNode *node;
    struct queNode *next;
} queNode;

void init(queNode **p, int val, struct TreeNode *node) {
    (*p) = (queNode *)malloc(sizeof(queNode));
    (*p)->val = val;
    (*p)->node = node;
    (*p)->next = NULL;
}

int minDepth(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    queNode *queLeft, *queRight;
    init(&queLeft, 1, root);
    queRight = queLeft;
    while (queLeft != NULL) {
        struct TreeNode *node = queLeft->node;
        int depth = queLeft->val;
        if (node->left == NULL && node->right == NULL) {
            return depth;
        }
        if (node->left != NULL) {
            init(&queRight->next, depth + 1, node->left);
            queRight = queRight->next;
        }
        if (node->right != NULL) {
            init(&queRight->next, depth + 1, node->right);
            queRight = queRight->next;
        }
        queLeft = queLeft->next;
    }
    return false;
}

 



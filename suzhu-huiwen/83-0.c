/*
。。。。只能说又没读题。。。。
O()
O()
*/

#include <stdio.h>
#include <string.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
}Node;

int main()
{
    struct ListNode* deleteDuplicates(struct ListNode* head);
    void Createlist_L1(struct ListNode **L,int n);
    struct ListNode * head;
    Createlist_L1(&head,1);
    deleteDuplicates(head);
    return 0;
}

void Createlist_L1(struct ListNode **L,int n) {
    struct ListNode * p,* r,* q;
    int ch=n;
    p =  *L = (struct ListNode * )malloc(sizeof(Node));
    p->val = n;
    p->next = NULL;
    r = p;
    while (ch!=0)
    {
        scanf("%d",&ch);
        p = (struct ListNode *) malloc(sizeof(Node));
        p->val = ch;
        r->next = p;
        q = r;
        r = p;
        /* code */
    }

    if((*L)->val !=0) q->next = NULL;
    else * L = NULL;
    
}


struct ListNode* deleteDuplicates(struct ListNode* head) {
    int t[200] = {};
    struct ListNode* p1,* p2;  
    p1 = p2 = head;
    while(p1 != NULL) {
        if (t[p1->val + 100] == 1) {
            p2->next = p1->next;
            p1 = p1->next;
        }
        else {
            t[p1->val + 100] = 1;
            p2 = p1;
            p1 = p1->next;
        }
    }
    return head;
}
    
/*
看不全为问题的情况；
感觉多少有点麻烦，有点傻逼；
O(M+N)
O(M+N)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
}Node;

int main()
{
      struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
      void Createlist_L1(struct ListNode **L,int n);
      struct ListNode * head1,* head2,* re; 
      
      Createlist_L1(&head1,1);
      Createlist_L1(&head2,1);
      //printf("%d\n",head1 -> val);
      re = mergeTwoLists(head1,head2);
      re = NULL;
      return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*------------------创建单链表(正位序尾插法)-----------------*/
void Createlist_L1(struct ListNode **L,int n){
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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
      struct ListNode * head,* p1,* p2,* NewNode;
      NewNode = p1 = p2 = head = (struct ListNode *)malloc(sizeof(Node));
      if(list1 == NULL && list2 == NULL) return NULL;
      while(list1 != NULL && list2 != NULL)
      {
            if(list1->val <= list2->val)
            {
                  p1->val = list1 -> val;
                  list1 = list1 -> next;
            }
            else 
            {
                  p1 -> val = list2 -> val;
                  list2 = list2 -> next;
            }
            NewNode = (struct ListNode *)malloc(sizeof(Node));
            p2 = p1;
            p1 = NewNode;
            p2 -> next = p1;
      }
      while(list1 != NULL)
      {
            p1->val = list1 -> val;
            list1 = list1 -> next;
            NewNode = (struct ListNode *)malloc(sizeof(Node));
            p2 = p1;
            p1 = NewNode;
            p2 -> next = p1;
      }
      while(list2 != NULL)
      {
            p1->val = list2 -> val;
            list2 = list2 -> next;
            NewNode = (struct ListNode *)malloc(sizeof(Node));
            p2 = p1;
            p1 = NewNode;
            p2 -> next = p1;
      }
      p2 -> next = NULL;
   return head;
}
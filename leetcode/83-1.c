struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* p1,* p2;
    p1 = p2 =head;
    while(p2 != NULL) {
        if(p2->val == p1->val) {
            p1->next = p2->next;
            p2 = p2->next;
        }
        else {
            p1 = p2;
            p2 = p2->next;
        }
    }
    return head;
}
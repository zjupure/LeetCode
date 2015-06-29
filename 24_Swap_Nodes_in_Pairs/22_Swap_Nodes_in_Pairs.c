/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    struct ListNode *pre = NULL, *cur = head, *post;
    head = head->next;
    while(cur != NULL && cur->next != NULL)
    {
        post = cur->next->next;
        cur->next->next = cur;
        cur->next = post;
        pre = cur;
        cur = cur->next;
        if(cur != NULL && cur->next != NULL)
            pre->next = cur->next;
    }
    
    return head;
}
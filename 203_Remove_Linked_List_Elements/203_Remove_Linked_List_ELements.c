/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL)
        return NULL;
    
    struct ListNode *cur = head, *pre;
    while(cur != NULL && cur->val == val)
    {
        cur = cur->next;
        free(head);
        head = cur;
    }
    
    if(cur == NULL)
        return NULL;
    
    pre = cur;
    cur = cur->next;
    while(cur != NULL)
    {
        if(cur->val == val)
        {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }
        else
        {
            cur = cur->next;
            pre = pre->next;
        }
    }
    
    return head;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    //no node || one node || two node
    if(head == NULL || head->next == NULL || head->next->next == NULL)
        return;
    
    struct ListNode *fast, *low;
    struct ListNode *pre, *cur, *post;
    
    fast = low = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        low = low->next;
    }
    //splite into two single link
    pre = NULL; cur = low->next; low->next = NULL;
    
    while(cur != NULL)
    {
        post = cur->next;
        cur->next = pre;
        pre = cur;
        cur = post;
    }
    
    fast = head;
    low = pre;
    //insertion
    while(low != NULL)
    {
        cur = low->next;
        low->next = fast->next;
        fast->next = low;
        fast = low->next;
        low = cur;
    }
    
    return;
}
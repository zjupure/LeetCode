/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *fast, *low;
    fast = low = head;
    
    while(n-- && fast != NULL)
    {
        fast = fast->next;
    }
    
    if(fast == NULL)
    {
        head = head->next;
        free(low);
        return head;
    }
    
    while(fast->next != NULL)
    {
        fast = fast->next;
        low = low->next;
    }
    
    fast = low->next;
    low->next = fast->next;
    free(fast);
    
    return head;
}
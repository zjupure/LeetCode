/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if(head == NULL)  return;
    
    struct ListNode *fast, *low, *mid;
    fast = low = head;
    
    while(low->next != NULL)
    {
        if(low->next->val < x)
        {
            if(fast->val >= x)
            {
                mid = low->next;
                low->next = mid->next;
                mid->next = fast;
                head = mid;
                fast = mid;
            }
            else if(low->next != fast->next)
            {
                mid = low->next;
                low->next = mid->next;
                mid->next = fast->next;
                fast->next = mid;
                fast = fast->next;
            }
            else
            {
                fast = fast->next;
                low = low->next;
            }
        }
        else
            low = low->next;
    }
    
    return head;
}
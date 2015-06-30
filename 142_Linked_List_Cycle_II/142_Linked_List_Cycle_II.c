/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast, *low;
    
    fast = low = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        low = low->next;
        
        if(fast == low)
        {
            fast = head;
            while(fast != low)
            {
                fast = fast->next;
                low = low->next;
            }
            return fast;
        }
    }
    
    return NULL;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast,*low;
    
    fast = low = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        low = low->next;
        
        if(fast == low)
            return true;
    }
    
    return false;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;
    
    struct ListNode *fast, *low;
    int n = 0;
    
    fast = low = head;
    while(fast != NULL && n < k)
    {
        fast = fast->next;
        n++;
    }
    
    if(fast == NULL)
    {
        k = k%n;
        if(k == 0)
            return head;
        fast = head;
        while(k--)
        {
            fast = fast->next;
        }
    }
        
    while(fast->next != NULL)
    {
        fast = fast->next;
        low = low->next;
    }
    //low-->splite node
    fast->next = head;
    head = low->next;
    low->next = NULL;
    
    return head;
}
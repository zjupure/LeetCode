/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    
    struct ListNode *head, *p = l1, *q = l2, *r;
    if(l1->val < l2->val)
    {
        head = l1;
        p = l1->next;
    }else
    {
        head = l2;
        q = l2->next;
    }
    
    r = head;
    while(p != NULL && q != NULL)
    {
        if(p->val < q->val)
        {
            r->next = p;
            p = p->next;
            r = r->next;
        }
        else
        {
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }
    
    if(p == NULL)
        r->next = q;
        
    if(q == NULL)
        r->next = p;
    
    return head;
}
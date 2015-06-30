/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p1 = headA;
    struct ListNode *p2 = headB;
    int m = 1<<20, n = 1<<20;
    int cnt = 0;
    
    while(true)
    {
        cnt++;
        if(cnt > m+n)
        {
            return NULL;
        }
        
        if(p1 == p2)
        {
            return p1;
        }
        
        if(p1 == NULL)
        {
            m = cnt;
            p1 = headB;
        }
        else
        {
            p1 = p1->next;
        }
        
        if(p2 == NULL)
        {
            n = cnt;
            p2 = headA;
        }
        else
        {
            p2 = p2->next;
        }
        
    }
}
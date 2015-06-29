/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if(m == n)
        return head;
    
    struct ListNode *first;
    struct ListNode *pre, *cur, *post, *tail;
    int cnt = 0;
    
    first = head;
    while(cnt < m-2)
    {    
        first = first->next;
        cnt++;
    }
    
    
    //start to reverse the middle link from m to n
    pre = NULL; cur = (m==1)?head:first->next; tail = cur;
    cnt = 0;
    while(cnt < n-m+1)
    {
        post = cur->next;
        cur->next = pre;
        pre = cur;
        cur = post;
        cnt++;
    }
    
    if(m == 1)
    {
        head = pre;
        tail->next = cur;
        //return head;
    }
    else
    {
        first->next = pre;
        tail->next = cur;
    }
    
    return head;
}
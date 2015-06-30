/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    struct ListNode *pre = NULL, *cur = head, *post;
    
    while(cur != NULL)
    {
        post = cur->next;   // save the next node
        cur->next = pre;
        pre = cur;
        cur = post;
    }
    
    return pre;
}
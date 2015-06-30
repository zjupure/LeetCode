/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    struct ListNode *cur = head->next;
    struct ListNode *pre,*post;
    
    head->next = NULL;
    while(cur != NULL)
    {
        if(cur->val < head->val)
        {
            post = cur->next;
            cur->next = head;
            head = cur;
            cur = post;
        }
        else
        {
            pre = head;
            post = cur->next;
            while(pre->next != NULL && pre->next->val <= cur->val)
                pre = pre->next;
            //insert the node
            cur->next = pre->next;
            pre->next = cur;
            cur = post;
        }
    }
    
    return head;
}
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    if(head == NULL)
        return NULL;
        
    struct RandomListNode *cur = head, *newNode, *newHead;
    
    while(cur != NULL)
    {
        newNode = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
        newNode->label = cur->label;
        //insert after cur;
        newNode->next = cur->next;
        newNode->random = NULL;
        cur->next = newNode;
        cur = newNode->next;
    }
    
    //start to copy
    cur = head;
    while(cur != NULL)
    {
        newNode = cur->next;
        if(cur->random != NULL)
            newNode->random = cur->random->next;
        cur = newNode->next;
    }
    
    //splite from the link
    cur = head; newHead = NULL;
    while(cur != NULL)
    {
        if(newHead == NULL)
        {
            newHead = cur->next;
            newNode = newHead;
        }
        else
        {
            newNode->next = cur->next;
            newNode = newNode->next;
        }
        cur->next = cur->next->next;
        cur = cur->next;
    }
    newNode->next = NULL;
    
    return newHead;
}
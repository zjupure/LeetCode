/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildBST(struct ListNode **head, int len)
{
    if(len <= 0)
        return NULL;

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    root->left = buildBST(head, len/2);

    root->val = (*head)->val;
    *head = (*head)->next;

    root->right = buildBST(head, len - len/2 - 1);

    return root;
}


struct TreeNode* sortedListToBST(struct ListNode* head) {
    if(head == NULL)  return NULL;

    struct ListNode *cur = head;
    int len = 0;

    while(cur != NULL)
    {
        len++;
        cur = cur->next;
    }
    cur = head;

    struct TreeNode *root = buildBST(&cur, len);

    return root;
}
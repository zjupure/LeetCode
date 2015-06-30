/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void BTreeToList(struct TreeNode* root, struct TreeNode** head, struct TreeNode** tail);

void flatten(struct TreeNode* root) {
    struct TreeNode *phead = NULL, *ptail = NULL;
    
    BTreeToList(root, &phead, &ptail);
}

void BTreeToList(struct TreeNode* root, struct TreeNode** head, struct TreeNode** tail)
{
    if(root == NULL)  return;
    
    struct TreeNode *phead = NULL, *ptail = NULL;
    
    *head = root; *tail = root;

    if(root->left != NULL)
    {
        BTreeToList(root->left, &phead, &ptail);
        phead->left = NULL; ptail->left = NULL;
        
        root->left = NULL;
        ptail->right = root->right;
        root->right = phead;
        *tail = ptail;
    }
    
    if(ptail == NULL)
        ptail = root;
    
    struct TreeNode *pheadx = NULL, *ptailx = NULL;
    if(ptail->right != NULL)
    {
        BTreeToList(ptail->right, &pheadx, &ptailx);
        pheadx->left = NULL; ptailx->left = NULL;
        *tail = ptailx;
    }
}
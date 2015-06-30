/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    if(root == NULL)  return;
    
    struct TreeLinkNode *cur = root, *post;
    
    while(cur->left != NULL && cur->right != NULL)
    {
        post = cur->left;  //save the left node
        do
        {
            cur->left->next = cur->right;
            if(cur->next != NULL)
            {
                cur->right->next = cur->next->left;
            }
            cur = cur->next;
        }while(cur != NULL);
        
        cur = post;
    }
    
    /*if(root == NULL) return;
    
    if(root->left != NULL && root->right != NULL)
    {
        root->left->next = root->right;
        if(root->next != NULL)
            root->right->next = root->next->left;
    }
    
    if(root->left != NULL)
        connect(root->left);
    
    if(root->right != NULL)
        connect(root->right);*/
}
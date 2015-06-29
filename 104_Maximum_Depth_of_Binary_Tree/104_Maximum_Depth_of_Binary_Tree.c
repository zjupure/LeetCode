/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int left = 0, right = 0;
    
    if(root == NULL)
        return 0;
    
    if(root->left != NULL)
        left = maxDepth(root->left);
    
    if(root->right != NULL)
        right = maxDepth(root->right);
    
    return left>right?left+1:right+1;
}
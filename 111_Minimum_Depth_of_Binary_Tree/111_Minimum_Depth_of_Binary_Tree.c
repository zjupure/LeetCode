/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    
    //leaf node
    if(root->left == NULL && root->right == NULL)
        return 1;
    
    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    
    if(root->left == NULL)
        return rh+1;
    else if(root->right == NULL)
        return lh+1;
    else
        return (lh<rh)?(lh+1):(rh+1);
}
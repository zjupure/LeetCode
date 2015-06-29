/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isChildSymmetric(struct TreeNode *p1, struct TreeNode *p2)
{
    if(p1 == NULL && p2 == NULL)
        return true;
    
    if(p1 == NULL || p2 == NULL)
        return false;
    
    if(p1->val != p2->val)
        return false;
    
    return isChildSymmetric(p1->left, p2->right) && isChildSymmetric(p1->right, p2->left);
}
 
 
bool isSymmetric(struct TreeNode* root) {
    if(root == NULL)
        return true;
    
    return isChildSymmetric(root->left, root->right);
}
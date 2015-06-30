/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//if the tree is balanced return a positive integer, other return -1;
int getDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    
    int lh = getDepth(root->left);
    int rh = getDepth(root->right);
    
    //child tree is not balanced
    if(lh == -1 || rh == -1)
        return -1;
    
    if(lh-rh >= -1 && lh-rh <= 1)
        return lh>rh?lh+1:rh+1;
    else
        return -1;
}

bool isBalanced(struct TreeNode* root) {
    if(getDepth(root) == -1)
        return false;
    else
        return true;
}
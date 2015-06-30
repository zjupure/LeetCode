/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool PathTravel(struct TreeNode *root, int curSum, int target)
{
    if(root == NULL)
        return false;
    
    //leaf node
    if(root->left == NULL && root->right == NULL)
    {
        if(curSum + root->val == target)
            return true;
        else
            return false;
    }
    
    return PathTravel(root->left, curSum + root->val,target) || PathTravel(root->right, curSum + root->val, target);
}


bool hasPathSum(struct TreeNode* root, int sum) {
    return PathTravel(root,0,sum);
}
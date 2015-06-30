/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum = 0;
void dfs(struct TreeNode *root, int curSum)
{
    if(root == NULL)
        return;
    
    curSum = curSum*10 + root->val;
    //leaf node
    if(root->left == NULL && root->right == NULL)
    {
        sum += curSum;
        return;
    }
    
    if(root->left != NULL)
        dfs(root->left, curSum);
    
    if(root->right != NULL)
        dfs(root->right, curSum);
}


int sumNumbers(struct TreeNode* root) {
    sum = 0;
    dfs(root,0);
    
    return sum;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> paths;
        
        getPathSum(root, paths, 0, sum);
        
        return ans;
    }
    
    void getPathSum(TreeNode* root, vector<int>& paths, int curSum, int target)
    {
        if(root == NULL)  return;
        
        curSum += root->val;
        
        if(root->left == NULL && root->right == NULL)
        {
            paths.push_back(root->val);
            if(curSum == target)
                ans.push_back(paths);
            
            paths.pop_back();
            return;
        }
        
        paths.push_back(root->val);
        if(root->left != NULL)
            getPathSum(root->left, paths, curSum, target);
        if(root->right != NULL)
            getPathSum(root->right, paths, curSum, target);
        paths.pop_back();
    }
};
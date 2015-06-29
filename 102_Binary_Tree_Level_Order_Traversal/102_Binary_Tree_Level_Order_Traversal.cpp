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
    //vector<vector<int> > ans;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        deque<pair<TreeNode*, int> > lqueue;
        
        if(root == NULL)  return res;
        
        lqueue.push_back(make_pair(root, 0));
        while(!lqueue.empty())
        {
            TreeNode *father = lqueue.front().first;
            int depth = lqueue.front().second;
            lqueue.pop_front();
            
            if(res.size() <= depth)
                res.push_back(vector<int>(1,father->val));
            else
                res[depth].push_back(father->val);
            
               
            if(father->left != NULL)
                lqueue.push_back(make_pair(father->left, depth+1));
            if(father->right != NULL)
                lqueue.push_back(make_pair(father->right, depth+1));
        }
        
        return res;
    }
    
    /*
    void levelOrderTravel(TreeNode* root, int depth)
    {
        if(root == NULL)  return;
        
        if(ans.size() <= depth)
        {
            ans.push_back(vector<int>(1,root->val));
        }
        else
        {
            ans[depth].push_back(root->val);
        }
        
        if(root->left != NULL)
            levelOrderTravel(root->left, depth+1);
        if(root->right != NULL)
            levelOrderTravel(root->right, depth+1);
    } */
};
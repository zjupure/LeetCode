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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        
        for(int i = 0, j = res.size()-1; i < j; i++, j--)
        {
            swap(res[i],res[j]);
        }
        
        return res;
    }
};
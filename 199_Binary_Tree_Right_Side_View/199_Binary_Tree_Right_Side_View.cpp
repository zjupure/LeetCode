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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        deque<pair<TreeNode*, int> > lqueue;
        
        if(root == NULL)  return ans;
        
        lqueue.push_back(make_pair(root, 0));
        while(!lqueue.empty())
        {
            TreeNode* father = lqueue.front().first;
            int depth = lqueue.front().second;
            lqueue.pop_front();
            
            if(!lqueue.empty())
            {
                int cdepth = lqueue.front().second;
                if(cdepth != depth)
                    ans.push_back(father->val);
            }
            else
            {
                ans.push_back(father->val);
            }
            
            if(father->left != NULL)
                lqueue.push_back(make_pair(father->left, depth+1));
            if(father->right != NULL)
                lqueue.push_back(make_pair(father->right, depth+1));
        }
        
        return ans;
    }
    
};
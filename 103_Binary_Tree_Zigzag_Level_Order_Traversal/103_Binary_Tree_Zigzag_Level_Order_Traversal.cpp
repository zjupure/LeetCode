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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        vector<int> levelres;
        deque<TreeNode*> zq1, zq2;
        
        if(root == NULL)  return res;
        
        zq1.push_back(root);
        while(!zq1.empty() || !zq2.empty())
        {
            
            while(!zq1.empty())
            {
                TreeNode *father = zq1.front();
                zq1.pop_front();
                
                levelres.push_back(father->val);
                
                if(father->left != NULL)
                    zq2.push_back(father->left);
                if(father->right != NULL)
                    zq2.push_back(father->right);
            }
            
            if(!levelres.empty())
            {
                res.push_back(levelres);
                levelres.clear();
            }
            
            while(!zq2.empty())
            {
                TreeNode *father = zq2.front();
                zq2.pop_front();
                
                levelres.push_back(father->val);
                
                if(father->left != NULL)
                    zq1.push_back(father->left);
                if(father->right != NULL)
                    zq1.push_back(father->right);
            }
            
            if(!levelres.empty())
            {
                // reverse
                for(int i = 0, j = levelres.size()-1; i < j; i++, j--)
                    swap(levelres[i], levelres[j]);
                
                res.push_back(levelres);
                levelres.clear();
            }
        }
        
        return res;
    }
    
};
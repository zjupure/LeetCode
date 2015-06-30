/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        
        deque<pair<TreeLinkNode*, int> > lqueue;
        lqueue.push_back(make_pair(root,0));
        while(!lqueue.empty())
        {
            pair<TreeLinkNode*, int> fpair = lqueue.front();
            lqueue.pop_front();
            TreeLinkNode *father = fpair.first;
            int depth = fpair.second;
            if(!lqueue.empty())
            {
                pair<TreeLinkNode *, int> cpair = lqueue.front();
                if(depth == cpair.second)
                    father->next = cpair.first;
            }
            //push the child node to the queue
            if(father->left != NULL)
                lqueue.push_back(make_pair(father->left, depth+1));
            if(father->right != NULL)
                lqueue.push_back(make_pair(father->right, depth+1));
            
        }
        
    }
};
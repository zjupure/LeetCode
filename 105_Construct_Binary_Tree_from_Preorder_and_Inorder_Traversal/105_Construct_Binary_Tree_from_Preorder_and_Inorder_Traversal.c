/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize <= 0)  return NULL;
    
    int val = preorder[0];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    root->val = val;
    
    int i;
    for(i = 0; i < inorderSize; i++)
    {
        if(val == inorder[i])
            break;
    }
    
    root->left = buildTree(&preorder[1], i, &inorder[0], i);
    root->right = buildTree(&preorder[i+1], preorderSize - i - 1, &inorder[i+1], inorderSize - i - 1);
    
    return root;
}
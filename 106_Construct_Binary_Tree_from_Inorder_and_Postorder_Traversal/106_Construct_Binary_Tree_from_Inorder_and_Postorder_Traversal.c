/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if(inorderSize <= 0)  return NULL;
    
    int val = postorder[postorderSize-1];
    struct TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    
    root->val = val;
    
    int i;
    for(i = 0; i < inorderSize; i++)
    {
        if(val == inorder[i])
            break;
    }
    
    root->left  = buildTree(&inorder[0], i, &postorder[0], i);
    root->right = buildTree(&inorder[i+1], inorderSize - i - 1, &postorder[i], postorderSize - i - 1);
    
    return root;
}
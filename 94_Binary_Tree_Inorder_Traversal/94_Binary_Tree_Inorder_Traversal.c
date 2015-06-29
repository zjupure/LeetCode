/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *tmp = (int *)malloc(sizeof(int)*10000);
    struct TreeNode *stk[10000];
    struct TreeNode *cur = root;
    int top = -1;
    int len = 0;
    
    do{
        while(cur != NULL)
        {
            stk[++top] = cur;
            cur = cur->left;
        }
        
        if(top != -1)
        {
            cur = stk[top--];
            tmp[len++] = cur->val;
            cur = cur->right;
        }
    }while(top != -1 || cur != NULL);
    
    *returnSize = len;
    if(len == 0) return NULL;
    else
    {
        int *res = (int *)malloc(sizeof(int)*len);
        memcpy(res,tmp,sizeof(int)*len);
        free(tmp);
        return res;
    }
}
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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *tmp = (int *)malloc(sizeof(int)*10000);
    struct TreeNode *stack[10000];
    int top = -1;
    int len = 0;
    struct TreeNode *cur = root;
    
    do
    {
        while(cur != NULL)
        {
            tmp[len++] = cur->val;  //output
            stack[++top] = cur;  // push to the stack
            cur = cur->left;  // left child
        }
        // assert the stack is not empty
        if(top != -1)
        {
            cur = stack[top--];  // pop the top element from the stack
            cur = cur->right;    // right child
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
    
    //return tmp;
}
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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *tmp = (int *)malloc(sizeof(int)*10000);
    struct TreeNode *stk[10000];
    int top = -1;
    int len = 0;
    struct TreeNode *cur = root;
    
    while(true)
    {
        do{
            while(cur != NULL)
            {
                stk[++top] = cur;  //push to the stack
                cur = cur->left;   // left child
            }
            if(top != -1)
            {
                cur = stk[top];  // get the top element but don't pop
                cur = cur->right; // push the right child to stack
            }
        }while(cur != NULL);
        
        while(top != -1)
        {
            tmp[len++] = stk[top--]->val;  //pop from the stack
            if(top == -1) break;
            if(stk[top+1] != stk[top]->right) break;  //return from the left child
        }
        
        if(top == -1) break;
        cur = stk[top]->right;
    }
    
    *returnSize = len;
    if(len == 0) return NULL;
    int *res = (int *)malloc(sizeof(int)*len);
    memcpy(res,tmp,sizeof(int)*len);
    free(tmp);
    return res;
}
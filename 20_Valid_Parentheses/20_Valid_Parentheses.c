bool isValid(char* s) {
    bool valid = true;
    char stk[1000];
    int top = 0, i = 0;
    
    while(s[i] != '\0')
    {
        // stack is empty
        if(top == 0)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk[top++] = s[i];  // push to the stack
            else
            {
                valid = false;
                break;
            }
        }
        else if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stk[top++] = s[i];  // push to the stack
        }
        else if((s[i] == ')' && stk[top-1] == '(') || (s[i] == ']' && stk[top-1] == '[') || (s[i] == '}' && stk[top-1] == '{'))
        {
            top--;  // pop from the stack
        }
        else
        {
            valid = false;
            break;
        }
        
        i++;
    }
    
    if(top > 0)
        valid = false;
    
    return valid;
}
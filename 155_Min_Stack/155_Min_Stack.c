typedef struct {
    int maxSize;
    int top;
    int *masterStk;
    int *slaveStk;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->maxSize = maxSize;
    stack->top = 0;
    stack->masterStk = (int *)malloc(sizeof(int)*maxSize);
    stack->slaveStk = (int *)malloc(sizeof(int)*maxSize);
}

void minStackPush(MinStack *stack, int element) {
    if(stack->top == 0)
    {
        stack->masterStk[stack->top] = element;
        stack->slaveStk[stack->top] = element;
        stack->top++;
    }
    else if(stack->top < stack->maxSize)
    {
        stack->masterStk[stack->top] = element;
        int min = stack->slaveStk[stack->top-1];
        if(element < min)
            stack->slaveStk[stack->top] = element;
        else
            stack->slaveStk[stack->top] = min;
        stack->top++;
    }
}

void minStackPop(MinStack *stack) {
    if(stack->top > 0)
        stack->top--;
}

int minStackTop(MinStack *stack) {
    if(stack->top > 0)
        return stack->masterStk[stack->top-1];
}

int minStackGetMin(MinStack *stack) {
    if(stack->top > 0)
        return stack->slaveStk[stack->top-1];
}

void minStackDestroy(MinStack *stack) {
    if(stack->masterStk != NULL)
        free(stack->masterStk);
    if(stack->slaveStk != NULL)
        free(stack->slaveStk);
}
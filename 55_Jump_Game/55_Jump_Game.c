bool canJump(int* nums, int numsSize) {
    int cur = 0, next = 0, maxStep = 0;
    
    while(cur < numsSize - 1)
    {
        if(cur + nums[cur] >= numsSize - 1)
        {
            cur = numsSize - 1;
            break;
        }
        
        maxStep = 0;
        for(int i = cur+1; i < cur+1+nums[cur]; i++)
        {
            if(i - cur + nums[i] > maxStep)
            {
                maxStep = i - cur + nums[i];
                next = i;
            }
        }
        cur = next;
        if(nums[cur] == 0)
            break;
    }
    
    if(cur >= numsSize-1)
        return true;
    else 
        return false;
}
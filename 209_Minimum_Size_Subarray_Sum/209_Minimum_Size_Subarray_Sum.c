int minSubArrayLen(int s, int* nums, int numsSize) {
    int i = 0, j = 0;
    int sum = 0, len = numsSize + 1;
    
    while(i < numsSize && j <= numsSize)
    {
        if(sum >= s)
        {
            if(len > j-i)
                len = j-i;
            sum -= nums[i];
            i++;
        }
        
        if(sum < s)
        {
            if(j < numsSize)
            {
                sum += nums[j];
                j++;
            }
            else
                break;
        }
    }
    
    return (len == numsSize+1) ? 0: len;
}
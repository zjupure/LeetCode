int removeDuplicates(int* nums, int numsSize) {
    if(numsSize <= 2)
        return numsSize;
    
    int last = nums[0];
    int cur = 1;
    int cnt = 1;
    
    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] != last)
        {
            nums[cur++] = nums[i];
            last = nums[i];
            cnt = 1;
        }
        else
        {
            cnt++;
            if(cnt <= 2)
                nums[cur++] = nums[i];
        }
    }
    
    return cur;
}
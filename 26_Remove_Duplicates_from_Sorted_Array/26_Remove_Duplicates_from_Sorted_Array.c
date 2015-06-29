int removeDuplicates(int* nums, int numsSize) {
    if(numsSize <= 1)
        return numsSize;
    
    int last = nums[0];
    int cur = 1;
    
    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] != last)
        {
            nums[cur++] = nums[i];
            last = nums[i];
        }
    }
    
    return cur;
}
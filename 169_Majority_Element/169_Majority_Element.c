int majorityElement(int* nums, int numsSize) {
    int cnt = 0;
    int res;
    
    for(int i = 0; i < numsSize; i++)
    {
        if(cnt == 0)
        {
            res = nums[i];
            cnt = 1;
        }
        else if(res == nums[i])
            cnt++;
        else
            cnt--;
    }
    
    return res;
}
void reverse(int *nums, int begin, int end)
{
    while(begin < end)
    {
        int tmp = nums[end];
        nums[end] = nums[begin];
        nums[begin] = tmp;
        begin++;end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    int n = numsSize;
    
    if(k >= n)
        k %= n;
    
    if(k == 0 || n <= 1)
        return;
    
    reverse(nums,0,n-k-1);
    reverse(nums,n-k,n-1);
    reverse(nums,0,n-1);
}
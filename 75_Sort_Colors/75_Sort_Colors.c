void sortColors(int* nums, int numsSize) {
    int C[3] = {0};
    int *B = (int *)malloc(sizeof(int)*numsSize);
    
    for(int i = 0; i < numsSize; i++)
    {
        C[nums[i]]++;
    }
    
    for(int i = 1; i < 3; i++)
    {
        C[i] += C[i-1];
    }
    
    for(int i = numsSize-1; i >= 0; i--)
    {
        int pos = C[nums[i]];
        B[pos-1] = nums[i];
        C[nums[i]]--;
    }
    
    memcpy(nums,B,sizeof(int)*numsSize);
    free(B);
}
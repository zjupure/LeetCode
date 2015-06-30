/*
 *                Truth Table
 *       c   d1  d0  |   d1'  d0'
 *       0   0   0   |   0    0
 *       1   0   0   |   0    1
 *       0   0   1   |   0    1
 *       1   0   1   |   1    0
 *       0   1   0   |   1    0
 *       1   1   0   |   0    0
 *       0   1   1   |   x    x
 *       1   1   1   |   x    x
 *       
 *       (d1, d0): counter
 *       d1' = c&d0 + (~c)&d1
 *       d0' = c&(~d1)&(~d0) + (~c)&(~d1)&d0 = (c^d0)&(~d1)
 */

int singleNumber(int* nums, int numsSize) {
    int d0 = 0, d1 = 0, tmp;
    
    for(int i = 0; i < numsSize; i++)
    {
        tmp = (nums[i]&d0)|((~nums[i])&d1);
        d0 = (nums[i]^d0)&(~d1);
        d1 = tmp;
    }
    
    return d0;
}
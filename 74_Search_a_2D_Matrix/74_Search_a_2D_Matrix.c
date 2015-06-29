bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int m = matrixRowSize, n = matrixColSize;
    bool isFind = false;
    
    int low = 0, high = m*n-1, mid;
    int row, col;
    
    /* binary search */
    while(low <= high)
    {
        mid = (low + high)>>1;
        row = mid/n; col = mid%n;
        
        if(matrix[row][col] == target)
        {
            isFind = true;
            break;
        }
        else if(matrix[row][col] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return isFind;
}
int num = 0;

void dfs(int cur, int n, int *c)
{
    bool flag;

    if(cur == n)
    {
        num++;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        c[cur] = i;
        flag = true;
        //check the collisions
        for(int j = 0; j < cur; j++)
        {
            if(c[j] == c[cur] || j-cur == c[j]-c[cur] || j-cur == c[cur]-c[j])
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            dfs(cur+1,n,c);
        }
    }
}


int totalNQueens(int n) {
    int *c = (int *)malloc(sizeof(int)*n);
    memset(c,0,sizeof(int)*n);
    
    num = 0;
    dfs(0,n,c);
    free(c);
    return num;
}
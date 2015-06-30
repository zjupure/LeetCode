int compareVersion(char* version1, char* version2) {
    int i = 0, j = 0;
    int ret = 0;
    int f1 = 1, f2 = 1;
    int st1 = 0, st2 = 0;

    while(version1[i] != '\0' && version2[j] != '\0')
    {

        if(version1[i] == '0' && f1)
        {
            //skip the heading zero
            while(version1[i] != '\0' && version1[i] == '0')
                i++;
            st1 = i;
            f1 = 0;
        }

        if(version2[j] == '0' && f2)
        {
            //skip the heading zero
            while(version2[j] != '\0' && version2[j] == '0')
                j++;
            st2 = j;
            f2 = 0;
        }

        if(version1[i] == '\0' || version2[j] == '\0')
            break;

        if(version1[i] == '.')
            f1 = 1;
        if(version2[j] == '.')
            f2 = 1;

        if(version1[i] != version2[j])
        {
            ret = version1[i]>version2[j]?1:-1;
            break;
        }
        i++;
        j++;
    }
    //break from '\0'
    if(ret == 0)
    {
        if(version1[i] == '\0' && version2[j] == '\0')
            return 0;
        else if(version1[i] == '\0')
        {
            if(version2[j] == '.')
            {
                while(version2[j] != '\0')
                {
                    if(version2[j] >= '1' && version2[j] <= '9')
                        return -1;
                    j++;
                }
                return 0;
            }

            return -1;
        }
        else
        {
            if(version1[i] == '.')
            {
                while(version1[i] != '\0')
                {
                    if(version1[i] >= '1' && version1[i] <= '9')
                        return 1;
                    i++;
                }
                return 0;
            }
            
            return 1;
        }
    }
    
    //break from two different value
    while(version1[i] != '\0')
    {
        if(version1[i] == '.')
            break;
        i++;
    }

    while(version2[j] != '\0')
    {
        if(version2[j] == '.')
            break;
        j++;
    }

    if(i-st1 == j-st2)
        return ret;
    else
        return (i-st1>j-st2)?1:-1;
}
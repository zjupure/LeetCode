int myAtoi(char* str) {
    int ret = 0;
    int sign = 1;
    
    while(*str == ' ') str++;   // skip leading zeros
    
    if(*str == '+')   // judge the sign bit
    {
        sign = 1;
        str++;
    }
    else if(*str == '-')
    {
        sign = -1;
        str++;
    }
    
    while(*str != '\0')
    {
        if(*str == ' ')   // break when encounter a blank
            break;
        
        if(*str < '0' || *str > '9')  // break when encounter a illegal character
            break;
            
        if(ret > INT_MAX/10)       // overflow
            return sign > 0?INT_MAX:INT_MIN;
        else if(ret == INT_MAX/10)
        {
            if(sign > 0 && *str > '7')  // up overflow
                return INT_MAX;
            if(sign < 0 && *str > '8')  // down overflow
                return INT_MIN;
        }
        
        ret = ret*10 + *str - '0';  // multiple *10
        str++;
    }
    
    return sign*ret;
}
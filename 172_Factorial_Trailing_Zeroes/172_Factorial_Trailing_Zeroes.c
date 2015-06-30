/*
 *  n! = n*(n-1)*(n-2)*...*2*1
 *  n! = 2^x*3^y*5^z*7*u.....
 *  x >= z, 2*5 = 10, count the z appear time
 *  5 appear in 5, 10, 15, 20, 25, .....
 *  while 25, 50.... contain two 5;
 *  z = n/5 + n/(5^2) + n/(5^3) + ... + n/(5^k);   5^k > n
 *
*/
int trailingZeroes(int n) {
    int ret = 0;
    
    while(n)
    {
        ret += n/5;
        n /= 5;
    }
    
    return ret;
}
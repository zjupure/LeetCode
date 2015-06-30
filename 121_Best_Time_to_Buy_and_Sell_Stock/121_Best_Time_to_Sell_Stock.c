int maxProfit(int* prices, int pricesSize) {
    int minPrice = 1<<30;
    int maxPro = 0;
    
    for(int i = 0; i < pricesSize; i++)
    {
        if(prices[i] - minPrice > maxPro)
            maxPro = prices[i] - minPrice;
        
        if(prices[i] < minPrice)
            minPrice = prices[i];
    }
    
    return maxPro;
}
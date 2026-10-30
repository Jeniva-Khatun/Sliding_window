int maxProfit(int* prices, int pricesSize) {
   int minPrice = prices[0];
   int maxProfit = 0;

   for(int i = 1; i < pricesSize ; i++ ){
    if (prices[i] < minPrice ){
        minPrice = prices[i];
    }
    else {
        int Profit = prices[i] - minPrice;
        if (Profit > maxProfit ){
            maxProfit= Profit;
        }
    }
   } 
   return maxProfit;
}

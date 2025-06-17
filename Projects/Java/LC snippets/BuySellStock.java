// 2. Best Time to Buy and Sell Stock
// You are given an array of prices where prices[i] is the price of a
// given stock on an ith day.
// You want to maximize your profit by choosing a single day to buy
// one stock and choosing a different day in the future to sell that
// stock.
// Return the maximum profit you can achieve from this transaction.
// If you cannot achieve any profit, return 0
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6),
// profit = 6-1 = 5.



class BuySellStock {
    public static void main(String[] args) {

        //given prices[ ] = price of a given stock on diff days
        // find best day to buy and best day after that to sell

        // given test case
        int prices[] = {7,1,5,3,6,4};
        
        // code
        int profit = 0;
        int potential = 0;
        int n = prices.length;
        for(int buy = 0; buy<n-1; buy++)
        {
            for (int sell = buy+1; sell<n; sell++)
            {
                potential = sell-buy;
                if(potential>profit)
                {
                    profit=potential;
                }
            }
        }

        System.out.println(profit);

    }
}
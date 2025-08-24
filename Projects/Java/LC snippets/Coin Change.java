//INCOMPLETE- check instabyte
// Coin Change

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1


class coinChange
{
    public static void main(String[] args)
    {
        int test_coins[] = {1,2,5};
        int test_target = 11;
        int result = coinChange(test_coins, test_target);
        System.out.println(result);
    }
    public static int coinChange(int[] coins, int target_amount)
    {
        int count=0;
        int sum = 0;
        for(int a = coins.length-1; a>=0; a--)
        {
            while((sum<target_amount) && ((sum+coins[a])<=target_amount))
            {
                sum +=coins[a];
                count++;
            
        
        }
        }
        if(sum == target_amount)
            {
                return count;
            }
        
        
        return -1;
    }
}
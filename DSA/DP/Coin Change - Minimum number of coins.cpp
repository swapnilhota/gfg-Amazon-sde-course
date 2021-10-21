/*
You are given an amount denoted by value. You are also given an array of coins. The array contains the
denominations of the give coins. You need to find the minimum number of coins to make the change for value using the coins of given denominations. Also, keep in mind that you have infinite supply of the
*/

const int M = 1e5;
int dp[1002][1002];
class Solution
{
    public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.
    long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
    {
        int n = numberOfCoins;
        memset(dp, -1, sizeof(dp));
        
        int ans = helper(coins, n, value);
        
        if(ans>=M)
        {
            return -1;
        }
        
        return ans;
    }
    
    int helper(int* coins, int n, int value)
    {
        if(value==0)
        {
            return 0;
        }
        if(n==0)
        {
            return M;
        }
        if(dp[n][value]!=-1)
        {
            return dp[n][value];
        }
        
        if(coins[n-1]<=value)
        {
            return dp[n][value] = min(helper(coins, n-1, value), 1+helper(coins, n, value-coins[n-1]));
        }
        else
        {
            return dp[n][value] = helper(coins, n-1, value);
        }
    }
};

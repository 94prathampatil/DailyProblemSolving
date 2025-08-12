class Solution {
public:
    int solve(int i, int isBuy, int fee, vector<int> &prices, vector<vector<int>>& dp){
        // Base Case
        if(i == prices.size())  return 0;

        if(dp[i][isBuy] != -1)
            return dp[i][isBuy];

        int profit = 0;
        if(isBuy){
            int buy = -prices[i] + solve(i + 1, !isBuy, fee, prices, dp);    
            int notBuy = solve(i + 1, isBuy, fee, prices, dp);
            profit = max(buy, notBuy);
        }
        else{
            int sell = prices[i] + solve(i + 1, !isBuy, fee, prices, dp);
            int notSell = solve(i + 1, isBuy, fee, prices, dp);
            profit = max(sell - fee, notSell);
        }

        return dp[i][isBuy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(0, 1, fee, prices, dp);
    }
};
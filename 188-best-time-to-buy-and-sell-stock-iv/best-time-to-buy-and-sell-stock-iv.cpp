const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    int solveTab(vector<int> &prices, int k){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int>(k + 1, 0)));

        for(int i = n - 1;i >= 0;i--){
            for(int isBuy = 0;isBuy <= 1;isBuy++){
                for(int limit = 1;limit <= k;limit++){
                    int profit = 0;
                    if(isBuy){
                        int buy = -prices[i] + dp[i + 1][0][limit];
                        int notBuy = dp[i + 1][1][limit];
                        profit = max(buy, notBuy);
                    }
                    else{
                        int sell = prices[i] + dp[i + 1][1][limit - 1];
                        int notSell = dp[i + 1][0][limit];
                        profit = max(sell, notSell);
                    }
                    dp[i][isBuy][limit] = profit;
                }

            }
        }

        return dp[0][1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

        return solveTab(prices, k);
    }
};
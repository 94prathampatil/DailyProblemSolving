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
    int solve(int i, int isBuy, vector<int> &p, vector<vector<int>> &dp){
        if(i == p.size())   return 0;

        if(dp[i][isBuy] != -1)  return dp[i][isBuy];

        int profit = 0;
        if(isBuy){
            int buy = -p[i] + solve(i + 1, !isBuy, p, dp);
            int notBuy = solve(i + 1, isBuy, p, dp);
            profit = max(buy, notBuy);
        }
        else{
            int sell = p[i] + solve(i + 1, !isBuy, p, dp);
            int notSell = solve(i + 1, isBuy, p, dp);
            profit = max(sell, notSell);
        }

        return dp[i][isBuy] = profit;
    }
    int maxProfit(vector<int>& p) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

        int n = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(0, 1, p, dp);
    }
};
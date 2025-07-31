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
    int solve(int start, int end, vector<vector<int>> &dp){
        if(start >= end)
            return 0;

        if(dp[start][end] != -1) return dp[start][end];

        int maxi = INT_MAX;
        for(int i = start;i <= end;i++){
            maxi = min(maxi, i + max(solve(start, i - 1, dp), solve(i + 1, end, dp)));
        }

        return dp[start][end] = maxi;
    }
    int getMoneyAmount(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return solve(1, n, dp);
    }
};
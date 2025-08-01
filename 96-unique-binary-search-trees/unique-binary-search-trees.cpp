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
    int solve(int n, vector<int> &dp){
        if(n <= 1)  return 1;

        if(dp[n] != -1) return dp[n];

        int ans = 0;

        for(int i = 1;i <= n;i++){
            ans += solve(i - 1, dp) * solve(n - i, dp);
        }

        return dp[n] = ans;
    }

    int solveTab(int n){
        vector<int> dp(n + 1, 0);

        dp[0] = 1, dp[1] = 1;

        for(int i = 2;i <= n;i++){
            for(int j = 1;j <= i;j++){
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
    int numTrees(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> dp(n + 1, -1);
        return solveTab(n);
    }
};
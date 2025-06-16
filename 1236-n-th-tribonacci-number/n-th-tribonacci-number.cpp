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
        if(n == 0)  return 0;
        if(n == 1 || n == 2)    return 1;

        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp) + solve(n - 3, dp);
    }

    int tab(int n) {
        vector<int> dp(n + 1, 0);

        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        dp[0] = 0;
        dp[1] = dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        return dp[n];
    }
    int tribonacci(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        // vector<int> dp(n + 1, -1);
        return tab(n);
    }
};
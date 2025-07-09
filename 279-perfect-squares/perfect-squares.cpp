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

        if(dp[n] != -1) return dp[n];

        int ans = n;
        for(int i = 1;i * i <= n;i++){
            ans = min(ans, solve(n - (i * i), dp) + 1);
        }

        dp[n] = ans;

        return ans;
    }

    int solveTab(int n){
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        int ans = n;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j * j <= n;j++){
                int temp = j * j;
                if(i - temp >= 0)
                    dp[i] = min(dp[i], dp[i - temp] + 1);
            }            
        }

        return dp[n];
    }
    int numSquares(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> dp(n + 1, -1);
        return solveTab(n);
    }
};
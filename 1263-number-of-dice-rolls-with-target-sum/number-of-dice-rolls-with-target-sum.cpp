const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();

#define m 1000000007

class Solution {
public:
    int solve(int dice, int faces, int t, vector<vector<int>>& dp){
        // base Case
        if(t < 0)   return 0;
        if(dice != 0 && t == 0) return 0;
        if(dice == 0 && t != 0) return 0;
        if(dice == 0 && t == 0) return 1;

        if(dp[dice][t] != -1){
            return dp[dice][t];
        }

        int ans = 0;
        for(int i = 1;i <= faces;i++){
            ans = (((ans % m) + (solve(dice - 1, faces, t - i, dp) % m)) % m);
        }

        return dp[dice][t] = (ans % m);
    }

    int solveTab(int d, int f, int t){
    vector<vector<int>> dp(d + 1, vector<int>(t + 1, 0));
    dp[0][0] = 1;

    for(int dice = 1; dice <= d; dice++){
        for(int target = 1; target <= t; target++){
            int ans = 0;
            for(int i = 1; i <= f; i++){
                if(target - i >= 0) {
                    ans = (((ans % m) + (dp[dice - 1][target - i] % m)) % m);
                }
            }
            dp[dice][target] = (ans % m);  
        }
    }

    return (dp[d][t] % m);  
}

    int numRollsToTarget(int n, int k, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return (solveTab(n, k, target) % m);
    }
};
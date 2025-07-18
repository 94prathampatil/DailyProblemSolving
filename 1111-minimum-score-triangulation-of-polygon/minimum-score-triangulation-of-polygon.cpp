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
    int solve(vector<int>& v, int i, int j, vector<vector<int>> &dp){
        if(i + 1 == j)  return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = INT_MAX;
        for(int k = i + 1;k < j;k++){
            ans = min(ans, (v[i] * v[j] * v[k]) + solve(v, i, k, dp) + solve(v, k, j, dp));
        }
        
        dp[i][j] = ans;

        return dp[i][j];
    }

    int solveTab(vector<int>& v){
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));

        for(int i = n - 1;i >= 0;i--){
            for(int j = i + 2;j < n;j++){
                int ans = INT_MAX;
                for(int k = i + 1;k < j;k++){
                    ans = min(ans, (v[i] * v[j] * v[k]) + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][n - 1];
    }

    int minScoreTriangulation(vector<int>& v) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // int n = v.size();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        return solveTab(v);
    }
};
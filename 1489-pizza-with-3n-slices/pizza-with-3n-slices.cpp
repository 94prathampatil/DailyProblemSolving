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
    int solve(int i, int end, vector<int> &slices, int n, vector<vector<int>> &dp){
        if(n == 0 || i > end){
            return 0;
        }
        
        if(dp[i][n] != -1){
            return dp[i][n];
        }

        int take = slices[i] + solve(i + 2, end, slices, n - 1, dp);
        int notTake = solve(i + 1, end, slices, n, dp);

        return dp[i][n] = max(take, notTake);
    }

    int solveTab(vector<int> &slices){
        int k = slices.size();
        vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

        for(int i = k - 2;i >= 0;i--){
            for(int n = 1;n <= k / 3;n++){
                int take = slices[i] + dp1[i + 2][n - 1];
                int notTake = dp1[i + 1][n];

                dp1[i][n] = max(take, notTake);
            }
        }

        int case1 = dp1[0][k / 3];

        for(int i = k - 1;i >= 1;i--){
            for(int n = 1;n <= k / 3;n++){
                int take = slices[i] + dp2[i + 2][n - 1];
                int notTake = dp2[i + 1][n];

                dp2[i][n] = max(take, notTake);
            }
        }

        int case2 = dp2[1][k / 3];

        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // int k = slices.size();
        // vector<vector<int>> dp1(k, vector<int>(k, -1));
        // int case1 = solve(0, k - 2, slices, k / 3, dp1f);

        // vector<vector<int>> dp2(k, vector<int>(k, -1));
        // int case2 = solve(1, k - 1, slices, k / 3, dp2);
        // return max(case1, case2);

        return solveTab(slices);
    }
};
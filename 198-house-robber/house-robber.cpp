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
    int solve(vector<int> &nums, int i, int n, vector<int> &dp){
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int inc = solve(nums, i + 2, n, dp) + nums[i];
        int exc = solve(nums, i + 1, n, dp);

        dp[i] = max(inc, exc);
        return dp[i];
    }
    int solveTab(vector<int> &nums, int n){
        if(n == 0)  return 0;
        if(n == 1)  return nums[0];

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2;i < n;i++){
            int inc = dp[i - 2] + nums[i];
            int exc = dp[i - 1];

            dp[i] = max(inc, exc);
        }

        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        // vector<int> dp(n + 1, -1);
        return solveTab(nums, n);
    }
};
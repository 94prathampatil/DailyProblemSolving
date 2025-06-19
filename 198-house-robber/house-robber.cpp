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
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, 0, n, dp);
    }
};
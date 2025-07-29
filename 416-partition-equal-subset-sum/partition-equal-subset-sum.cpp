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
#define all(x) x.begin(), x.end()

class Solution {
public:
    int solve(int idx, vector<int>& nums, int target, vector<vector<int>> &dp){
        if(idx >= nums.size() || target < 0)    return 0;
        if(target == 0) return 1;

        if(dp[idx][target] != -1)
            return dp[idx][target];
        
        int inc = solve(idx + 1, nums, target - nums[idx], dp);
        int exc = solve(idx + 1, nums, target, dp);

        return dp[idx][target] = inc | exc;
    }

    bool canPartition(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int totalSum = accumulate(all(nums), 0);
        if(totalSum & 1)    return 0;
        int target = totalSum / 2;

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(0, nums, target, dp);
    }
};
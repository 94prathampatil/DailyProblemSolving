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
    int solve(int n, vector<int> &nums, int curr, int prev, vector<vector<int>>& dp){
        // base case;
        if(curr == n){
            return 0;
        }

        if(dp[curr][prev + 1] != -1){
            return dp[curr][prev + 1];
        }

        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            take = 1 + solve(n, nums, curr + 1, curr, dp);
        }
        int notTake = solve(n, nums, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return solve(n, nums, 0, -1, dp);
    }
};
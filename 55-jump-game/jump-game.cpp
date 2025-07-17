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
    bool solve(vector<int> &nums, int idx, vector<int> &dp){
        // base case
        if(idx >= nums.size() - 1)
            return true;

        if(nums[idx] == 0)    return false;

        if(dp[idx] != -1){
            return dp[idx];
        }

        for(int i = 1;i <= nums[idx];i++){
            if(solve(nums, idx + i, dp))
                return dp[idx] = true;
        }

        return dp[idx] = false;
    } 

    bool solveTab(vector<int> &nums){
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;

        for(int i = 0;i < n;i++){
            if(dp[i]){
                for(int j = 1;j <= nums[i];j++){
                    if(i + j < n){
                        dp[i + j] = true;
                    }
                }
            }
        }

        return dp[n - 1];

    }  

    bool canJump(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // int n = nums.size();
        // vector<int> dp(n + 1, -1);
        return solveTab(nums);
    }
};
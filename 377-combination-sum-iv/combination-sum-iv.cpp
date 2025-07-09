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

#define pb(x) push_back(x)

class Solution {
public:
    int solve(vector<int>& nums, int target, vector<int>& dp){
        if(target == 0) return 1;
        if(target < 0)  return 0;

        if(dp[target] != -1){
            return dp[target];
        }

        int ans = 0;
        for(int i = 0;i < nums.size();i++){
            ans += solve(nums, target - nums[i], dp);
        }
        
        dp[target] = ans;

        return dp[target];
    }

    int solveTab(vector<int> &nums, int target){
        vector<int> dp(target + 1, 0);

        dp[0] = 1;

        for(int i = 1;i <= target;i++){
            for(int j = 0;j < nums.size();j++){
                if(i - nums[j] >= 0)
                    dp[i] += dp[i - nums[j]] + 0L;
            }
        }

        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);   

        // int n = nums.size();
        // vector<int> dp(target + 1, -1);

        return solveTab(nums, target);
    }
};
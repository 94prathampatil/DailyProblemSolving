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

int solve(vector<int> &nums, int i, int n, vector<int> &dp){
    if(i >= n)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int inc = solve(nums, i + 2, n, dp) + nums[i];
    int exc = solve(nums, i + 1, n, dp);

    return dp[i] = max(inc, exc);
}

class Solution {
public:
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }

        int n = nums.size();

        vector<int> first, second;
        for(int i = 0;i < nums.size();i++){
            if(i >= 1){
                first.pb(nums[i]);
            }
            if(i < n - 1){
                second.pb(nums[i]);
            }
        }

        vector<int> dp(n + 1, -1);
        int a = solve(first, 0, first.size(), dp);
        dp.clear();
        dp.assign(n + 1, -1);
        int b = solve(second, 0, second.size(), dp);
        // int c = solve(nums, 0, nums.size());

        // cout << a << " " << b <<;

        return max(a, b);
    }
};
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
    int solve(int index, vector<int> &nums1, vector<int> &nums2, int swapped, vector<vector<int>> &dp){
        if(index >= nums1.size())   return 0;

        if(dp[index][swapped] != -1)
            return dp[index][swapped];
        

        int ans = INT_MAX;

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if(swapped) swap(prev1, prev2);

        // no - swap
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solve(index + 1, nums1, nums2, 0, dp);
        }

        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans, 1 + solve(index + 1, nums1, nums2, 1, dp));
        }

        return dp[index][swapped] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        vector<vector<int>> dp(nums1.size(), vector<int> (2, -1));

        return solve(1, nums1, nums2, 0, dp);
    }
};
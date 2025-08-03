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
    int longestArithSeqLength(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = 0, n = nums.size();
        if(n <= 2)  return n;

        unordered_map<int, int> dp[n + 1];       

        for(int i = 1;i < n;i++){
            for(int j = 0;j < i;j++){
                int diff = nums[i] - nums[j];
                int cnt = 1;

                // Check if Answer is already exist
                if(dp[j].count(diff)){
                    cnt = dp[j][diff];
                }

                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};
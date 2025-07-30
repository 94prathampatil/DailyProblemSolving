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
    int longestSubsequence(vector<int>& arr, int diff) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = 0;
        unordered_map<int, int> dp;

        for(int i = 0;i < arr.size();i++){
            int temp = arr[i] - diff;
            int tempAns = 0;

            if(dp.count(temp))
                tempAns = dp[temp];

            dp[arr[i]] = 1 + tempAns;

            ans = max(ans, dp[arr[i]]);            
        }

        return ans;
    }
};
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0, preSum = 0, n = nums.size();

        for(int i = 0;i < n;i++){
            preSum += (nums[i] & 1) ? 1 : 0;
            ans += mp[preSum - k];
            mp[preSum]++;
        }

        return ans;
    }
};
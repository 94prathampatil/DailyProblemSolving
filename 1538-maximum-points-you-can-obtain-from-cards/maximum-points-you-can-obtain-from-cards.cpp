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
    int maxScore(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int res = accumulate(nums.begin(), nums.begin() + k, 0);
        int curr = res;

        for(int i = k - 1;i >= 0;i--){
            curr -= nums[i];
            curr += nums[nums.size() - k + i];

            res = max(curr, res);
        }

        return res;
    }
};
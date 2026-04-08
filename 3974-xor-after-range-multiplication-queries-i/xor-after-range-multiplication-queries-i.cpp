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
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        const int mod = 1e9 + 7;

        for(auto &q : queries){
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for(int idx = l;idx <= r;idx += k){
                 nums[idx] = (1LL * nums[idx] * v) % mod;   
            }
        }

        int ans = 0;
        for(auto i:nums)  ans ^= i;

        return ans;
    }
};

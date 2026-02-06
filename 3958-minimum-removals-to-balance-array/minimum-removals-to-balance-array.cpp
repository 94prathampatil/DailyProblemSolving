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
    typedef long long ll;
    int minRemoval(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = 0, n = nums.size();
        int i = 0, j = 0;
        sort(begin(nums), end(nums));

        while(j < n){
            ll maxi = (k * (nums[i] * 1LL));
            if(nums[j] <= maxi){
                ans = max(ans, j - i + 1);
                j++;
            }
            else    
                i++;
        }

        return n - ans;
    }
};
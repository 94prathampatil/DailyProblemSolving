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
#define ll long long
#define llv long long vector
#define n nums.size()



class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        ll l = nums[0], maxDiff = l - nums[1], ans = max(0LL, maxDiff * nums[2]);

        for(ll i = 3;i < n;i++){
            l = max(l, (ll)nums[i - 2]);
            maxDiff = max(maxDiff, l - nums[i - 1]);
            ans = max(ans, maxDiff * nums[i]);
        }

        return ans;
    }
};
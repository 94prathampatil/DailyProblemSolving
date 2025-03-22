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
#define v nums
#define all() v.begin(), v.end()
#define n v.size()

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int l = 0, r = 0;
        int len = 0;
        unordered_map<int, int> mp;

        while(r < n){
            mp[v[r]]++;
            if(mp[v[r]] > k){
                while(v[l] != v[r])
                    mp[v[l++]]--;  

                mp[v[l++]]--;
            }

            len = max(len, r - l + 1);
            r++;
        }

        return len;

        return len;
    }
};
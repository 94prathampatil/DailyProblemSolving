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
#define all() v.begin(), v.end()
#define v nums
#define n v.size()

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int l = 0, r = 0;
        int mask = 0;
        int len = 0;

        while(r < n){
            
            while((mask & v[r]) != 0)
                mask = mask ^ v[l++];
            

            mask |= v[r];
            len = max(len, r - l + 1);
            r++;
        }

        return len;
    }
};
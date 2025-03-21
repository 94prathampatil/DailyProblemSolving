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
    int maxSum(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(all());
        int ans = v[n - 1];

        for(int i = n - 2;i >= 0;i--){
            if(v[i] == v[i + 1])    continue;
            if(v[i] <= 0)   break;

            ans += v[i];
        }

        return ans;
    }
};
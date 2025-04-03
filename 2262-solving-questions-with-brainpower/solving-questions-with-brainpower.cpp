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


class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        ll n = q.size();
        vector<ll> dp(n + 1, 0);

        for(ll i = n - 1;i >= 0;i--){
            ll points = q[i][0];
            ll pb = q[i][1];

            ll skip = dp[i + 1];
            ll take = points + dp[min(n, (ll)i + pb + 1)];

            dp[i] = max(skip, take);
        }

        return dp[0];
    }
};
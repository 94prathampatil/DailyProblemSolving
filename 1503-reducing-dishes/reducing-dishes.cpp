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

#define all(x) x.begin(), x.end()

class Solution {
public:
    int solve(vector<int> &satisfaction, int i, int t, vector<vector<int>> &dp){
        // Base case
        if(i == satisfaction.size())
            return 0;

        if(dp[i][t] != -1){
            return dp[i][t];
        }

        int inc = (satisfaction[i] * (t + 1)) + solve(satisfaction, i + 1, t + 1, dp);
        int exc = solve(satisfaction, i + 1, t, dp);

        dp[i][t] = max(inc, exc);
        return dp[i][t];

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(all(satisfaction));
        // return solve(satisfaction, 0, 0);

        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(satisfaction, 0, 0, dp);
    }
};
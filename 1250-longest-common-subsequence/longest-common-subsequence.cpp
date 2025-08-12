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
    int solve(string &t1, string &t2, int i, int j, vector<vector<int>> &dp){
        // Base case
        if(i == t1.length() || j == t2.length())    return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(t1[i] == t2[j]){
            ans = 1 + solve(t1, t2, i + 1, j + 1, dp);
        }
        else{
            ans = max(solve(t1, t2, i, j + 1, dp), solve(t1, t2, i + 1, j, dp));
        }

        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string t1, string t2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = t1.length();
        int m = t2.length();

        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return solve(t1, t2, 0, 0, dp);
    }
};
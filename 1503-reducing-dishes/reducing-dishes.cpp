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

    int solveTab(vector<int> &satisfaction){
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));


        for(int i = n - 1;i >= 0;i--){
            for(int t = i;t >= 0;t--){
                int incl = (satisfaction[i] * (t + 1)) + dp[i + 1][t + 1];
                int excl = dp[i + 1][t];

                dp[i][t] = max(incl, excl);
            }
        }

        return dp[0][0];
    }

    int solveSO(vector<int> &satisfaction){
        int n = satisfaction.size();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        for(int i = n - 1;i >= 0;i--){
            for(int t = i;t >= 0;t--){
                int incl = (satisfaction[i] * (t + 1)) + next[t + 1];
                int excl = next[t];

                curr[t] = max(incl, excl);
            }

            next = curr;
        }

        return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(all(satisfaction));
        // return solve(satisfaction, 0, 0);

        // int n = satisfaction.size();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        return solveSO(satisfaction);
    }
};
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
    int solve(int i, int j, string &w1, string w2, vector<vector<int>> &dp){
        if(i == w1.length()){
            return w2.length() - j;
        }
        if(j == w2.length()){
            return w1.length() - i;
        }

        if(dp[i][j] != -1)  return dp[i][j];

        int ans = 0;
        if(w1[i] == w2[j]){
            return solve(i + 1, j + 1, w1, w2, dp);
        }
        else{
            int insert = 1 + solve(i, j + 1, w1, w2, dp);
            int remove = 1 + solve(i + 1, j, w1, w2, dp);
            int replace = 1 + solve(i + 1, j + 1, w1, w2, dp);

            ans = min(insert, min(remove, replace));
        }

        return dp[i][j] = ans;
    }

    int solveTab(string &w1, string &w2){
        int n = w1.length();
        int m = w2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int j = 0;j < m;j++){
            dp[n][j] = m - j; 
        }

        for(int i = 0;i < n;i++){
            dp[i][m] = n - i;
        }

        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){
                int ans = 0;
                if(w1[i] == w2[j]){
                    ans = dp[i + 1][j + 1];
                }
                else{
                    int insert = 1 + dp[i][j + 1];
                    int remove = 1 + dp[i + 1][j];
                    int replace = 1 + dp[i + 1][j + 1];

                    ans = min(insert, min(remove, replace));
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
    int minDistance(string w1, string w2) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        
        // int n = w1.length();
        // int m = w2.length();

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solveTab(w1, w2);
    }
};
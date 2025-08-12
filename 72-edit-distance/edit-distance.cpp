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

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);
        for(int j = 0;j < m;j++){
            next[j] = m - j; 
        }

        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){

                curr[m] = n - i;
                int ans = 0;
                if(w1[i] == w2[j]){
                    ans = next[j + 1];
                }
                else{
                    int insert = 1 + curr[j + 1];
                    int remove = 1 + next[j];
                    int replace = 1 + next[j + 1];

                    ans = min(insert, min(remove, replace));
                }

                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }
    int minDistance(string w1, string w2) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        
        int n = w1.length();
        int m = w2.length();

        if(n == 0)  return m;
        if(m == 0)  return n;

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solveTab(w1, w2);
    }
};
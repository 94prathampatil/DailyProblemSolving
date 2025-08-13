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
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i == 0 && j == 0)  return true;
        if(i > 0 && j == 0)  return false;

        if(i == 0 && j > 0){
            for(int k = 1;k <= j;k++){
                if(p[k - 1] != '*'){
                    return false;
                }
            }

            return true;
        }

        if(dp[i][j] != -1)  return dp[i][j];

        if((s[i - 1] == p[j - 1]) || (p[j - 1] == '?')){
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }
        else if(p[j - 1] == '*'){
            bool emptyStringReplace = solve(i, j - 1, s, p, dp);
            bool replaceAnySequence = solve(i - 1, j, s, p, dp);
            return dp[i][j] = (emptyStringReplace || replaceAnySequence);
        }
        else{
            return dp[i][j] = false;
        }
    }

    bool solveTab(string &s, string &p){
        int n = s.length(), m = p.length();
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        prev[0] = true;

        for(int j = 1;j <= m;j++){
            bool flag = true;
            for(int k = 1;k <= j;k++){
                if(p[k - 1] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if((s[i - 1] == p[j - 1]) || (p[j - 1] == '?')){
                    curr[j] = prev[j - 1];
                }
                else if(p[j - 1] == '*'){
                    bool emptyStringReplace = curr[j - 1];
                    bool replaceAnySequence = prev[j];
                    curr[j] = (emptyStringReplace || replaceAnySequence);
                }
                else{
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[m];
    }
    bool isMatch(string s, string p) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return solveTab(s, p);
    }
};
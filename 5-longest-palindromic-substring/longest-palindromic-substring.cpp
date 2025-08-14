class Solution {
public:
    bool solve(int i, int j, string &s, vector<vector<int>> &dp){
        if(i >= j)  return true;

        if(dp[i][j] != -1){
            return dp[i][j];
        }


        if(s[i] == s[j]){
            return dp[i][j] = solve(i + 1, j - 1, s, dp);
        }
        
        return dp[i][j] = false;
        
    }
    string longestPalindrome(string s) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

        int n = s.length();
        int maxLen = INT_MIN;
        int start = 0;

        vector<vector<int>> dp(1001, vector<int> (1001, -1));

        for(int i = 0;i < n;i++){
            for(int j = i;j < n;j++){
                if(solve(i, j, s, dp) && j - i + 1 > maxLen){
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if (i == s1.length()) {
            int sum = 0;
            for (int k = j; k < s2.length(); k++) sum += s2[k];
            return sum;
        }
        if (j == s2.length()) {
            int sum = 0;
            for (int k = i; k < s1.length(); k++) sum += s1[k];
            return sum;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = solve(i + 1, j + 1, s1, s2, dp);
        }
        
        int s1Delete = s1[i] + solve(i + 1, j, s1, s2, dp);
        int s2Delete = s2[j] + solve(i, j + 1, s1, s2, dp);

        return dp[i][j] = min(s1Delete, s2Delete);
    }
    int minimumDeleteSum(string s1, string s2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = max(s1.length(), s2.length());

        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

        return solve(0, 0, s1, s2, dp);
    }
};
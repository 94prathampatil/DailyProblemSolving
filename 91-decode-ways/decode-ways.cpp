class Solution {
public:
    int solve(int i, string &s, vector<int> &dp){
        if (i == s.length())
            return 1;

        if (s[i] == '0')
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int one = solve(i + 1, s, dp);

        int two = 0;
        if (i + 1 < s.length()) {
            int val = stoi(s.substr(i, 2));
            if (val >= 10 && val <= 26)
                two = solve(i + 2, s, dp);
        }

        return dp[i] = one + two;
    }
    int numDecodings(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = s.length();
        vector<int> dp(n + 1, -1);

        return solve(0, s, dp);
    }
};
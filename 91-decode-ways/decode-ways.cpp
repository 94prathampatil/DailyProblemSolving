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

    int solveTab(string s){
        int n = s.length();
        vector<int> dp(n + 1, 0);

        dp[n] = 1;  

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            int one = dp[i + 1];
            int two = 0;

            if (i + 1 < n) {
                int val = stoi(s.substr(i, 2));
                if (val >= 10 && val <= 26) {
                    two = dp[i + 2];
                }
            }

            dp[i] = one + two;
        }

        return dp[0];
    }
    int numDecodings(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = s.length();
        vector<int> dp(n + 1, -1);

        return solveTab(s);
    }
};
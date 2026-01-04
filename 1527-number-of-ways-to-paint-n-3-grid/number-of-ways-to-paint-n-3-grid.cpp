#define m 1000000007

class Solution {
public:
    int solve(int n, int prev, vector<string> &state, vector<vector<int>> &dp) {
        if (n == 0) return 1;

        if(dp[n][prev] != -1)
            return dp[n][prev];

        int res = 0;
        string prevPattern = state[prev];

        for (int curr = 0; curr < 12; curr++) {
            bool conflict = false;
            string currPattern = state[curr];

            for (int col = 0; col < 3; col++) {
                if (prevPattern[col] == currPattern[col]) {
                    conflict = true;
                    break;
                }
            }

            if (!conflict) {
                res = (res + solve(n - 1, curr, state, dp)) % m;
            }
        }
        return dp[n][prev] = res;
    }

    int numOfWays(int n) {
        vector<vector<int>> dp(n, vector<int> (12, -1));
        vector<string> state = {
            "RGY","RYG","GRY","GYR","YRG","YGR",
            "RGR","RYR","GRG","GYG","YGY","YRY"
        };

        int res = 0;
        for (int i = 0; i < 12; i++) {
            res = (res + solve(n - 1, i, state, dp)) % m;
        }
        return res;
    }
};

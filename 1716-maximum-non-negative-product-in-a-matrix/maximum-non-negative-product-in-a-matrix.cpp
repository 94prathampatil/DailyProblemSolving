class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(m));

        dp[0][0] = {grid[0][0], grid[0][0]};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) continue;

                long long mx = LLONG_MIN, mn = LLONG_MAX;

                if(i > 0) {
                    auto [prevMax, prevMin] = dp[i-1][j];
                    mx = max({mx, prevMax * grid[i][j], prevMin * grid[i][j]});
                    mn = min({mn, prevMax * grid[i][j], prevMin * grid[i][j]});
                }

                if(j > 0) {
                    auto [prevMax, prevMin] = dp[i][j-1];
                    mx = max({mx, prevMax * grid[i][j], prevMin * grid[i][j]});
                    mn = min({mn, prevMax * grid[i][j], prevMin * grid[i][j]});
                }

                dp[i][j] = {mx, mn};
            }
        }

        long long ans = dp[n-1][m-1].first;
        return ans < 0 ? -1 : ans % MOD;
    }
};
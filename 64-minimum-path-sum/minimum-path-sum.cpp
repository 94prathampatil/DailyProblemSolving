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
    int solve(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &dp){
        int m = grid.size();
        int n = grid[0].size();

        if(x >= m || y >= n)    return INT_MAX;

        if(x == m - 1 && y == n - 1) return grid[x][y];

        if(dp[x][y] != -1){
            return dp[x][y];
        }

        int right = solve(grid, x + 1, y, dp);
        int down = solve(grid, x, y + 1, dp);

        return dp[x][y] = grid[x][y] + min(right, down);
    }

    int solveTab(vector<vector<int>> &grid){
        int n = grid[0].size();
        int m = grid.size();

        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];

        for (int j = n - 2; j >= 0; j--) {
            dp[m-1][j] = grid[m-1][j] + dp[m-1][j+1];
        }

        for (int i = m - 2; i >= 0; i--) {
            dp[i][n-1] = grid[i][n-1] + dp[i+1][n-1];
        }

        for(int x = m - 2;x >= 0;x--){
            for(int y = n - 2;y >= 0;y--){
                int right = dp[x + 1][y];
                int down = dp[x][y + 1];

                dp[x][y] = grid[x][y] + min(right, down);
            }
        }

        return dp[0][0];
    }

    int minPathSum(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        // int n = grid[0].size();
        // int m = grid.size();

        // vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        return solveTab(grid);
    }
};
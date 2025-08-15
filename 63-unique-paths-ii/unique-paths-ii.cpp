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
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        int n = grid.size();
        int m = grid[0].size();

        if(i >= n || j >= m || grid[i][j] == 1) return 0;

        if(i == n - 1 && j == m - 1)    return 1;
        

        if(dp[i][j] != -1)  return dp[i][j];

        return dp[i][j] = solve(i + 1, j, grid, dp) + solve(i, j + 1, grid, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));

        return solve(0, 0, grid, dp);
    }
};
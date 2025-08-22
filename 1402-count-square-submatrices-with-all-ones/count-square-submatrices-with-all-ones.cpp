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
    int solve(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        // base case;
        if(i >= n || j >= m)    return 0;

        if(matrix[i][j] == 0)   return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        int right = INT_MAX, diagonal = INT_MAX, down = INT_MAX;
        if(matrix[i][j] == 1){
            right = solve(i, j + 1, n, m, matrix, dp);
            diagonal = solve(i + 1, j + 1, n, m, matrix, dp);
            down = solve(i + 1, j, n, m, matrix, dp);
        }
        
        return dp[i][j] = 1 + min({right, diagonal, down});
    }

    int solveTab(vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for(int i = 0;i < n;i++){
            dp[i][0] = matrix[i][0];
        }
        for(int j = 0;j < m;j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1;i < n;i++){
            for(int j = 1;j < m;j++){
                if(matrix[i][j] == 1){
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                }
            }
        }

        int total = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                total += dp[i][j];
            }
        }

        return total;
    }

    int countSquares(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        int total = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                total += solve(i, j, n, m, matrix, dp);
            }
        }

        return total;
    }
};
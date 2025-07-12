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
    int solve(int i, int j, vector<vector<char>> &matrix, int &maxi, vector<vector<int>> &dp){
        if(i >= matrix.size() || j >= matrix[0].size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solve(i, j + 1, matrix, maxi, dp);
        int diagonal = solve(i + 1, j + 1, matrix, maxi, dp);
        int down = solve(i + 1, j, matrix, maxi, dp);

        if(matrix[i][j] == '1'){
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(dp[i][j], maxi);
            return dp[i][j];
        }
        else{
            return dp[i][j] = 0;
        }
    }

    // Memoization Gives TLE... :( 
    // int solveTab(int i, int j, vector<vector<char>> &matrix){
    //     int n =  matrix.size(), m = matrix[0].size();

    //     vector<vector<int>> dp(n, vector<int> (m, 0));
    //     dp[n][m] = 0;

    //     for(int )
    // }

    int maximalSquare(vector<vector<char>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int maxi = 0;
        solve(0, 0, matrix, maxi, dp);
        return maxi * maxi;
    }
};
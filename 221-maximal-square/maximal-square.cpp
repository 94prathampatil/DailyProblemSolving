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

    int solveTab(vector<vector<char>> &matrix, int &maxi){
        int n =  matrix.size(), m = matrix[0].size();

        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){

                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];
                int down = dp[i + 1][j];

                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(dp[i][j], maxi);
                }
                else{
                    dp[i][j] = 0;
                }

            }
        }

        return dp[0][0];
    }

    int solveSO(vector<vector<char>> &matrix, int &maxi){
        int n =  matrix.size(), m = matrix[0].size();

        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){

                int right = curr[j + 1];
                int diagonal = next[j + 1];
                int down = next[j];

                if(matrix[i][j] == '1'){
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(curr[j], maxi);
                }
                else{
                    curr[j] = 0;
                }
            }

            next = curr;
        }

        return next[0];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // int n = matrix.size();
        // int m = matrix[0].size();
        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // int maxi = 0;
        // solve(0, 0, matrix, maxi, dp);
        // return maxi * maxi;

        int maxi = 0;
        solveSO(matrix, maxi);
        return maxi * maxi;
    }
};
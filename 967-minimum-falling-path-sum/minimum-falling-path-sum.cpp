class Solution {
public:
    int solve(int row, int col, int n, vector<vector<int>>& mat, vector<vector<int>> &dp){
        if (col < 0 || col >= n)    
            return INT_MAX;

        if (row == n - 1)           
            return mat[row][col];

        if(dp[row][col] != INT_MIN)  return dp[row][col];

        int dLeft = solve(row + 1, col - 1, n, mat, dp);
        int dNext = solve(row + 1, col, n, mat, dp);
        int dRight = solve(row + 1, col + 1, n, mat, dp);

        int val = mat[row][col];
        if (dLeft != INT_MAX)  dLeft += val;
        if (dNext != INT_MAX)  dNext += val;
        if (dRight != INT_MAX) dRight += val;

        return dp[row][col] = min({dLeft, dNext, dRight});
    }
    int solveTab(vector<vector<int>> &mat, int col){
        int n = mat.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

        for(int i = 0;i < n;i++){
            dp[n - 1][i] = mat[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int dLeft  = (j > 0)     ? dp[i + 1][j - 1] : INT_MAX;
                int dNext  = dp[i + 1][j];
                int dRight = (j < n - 1) ? dp[i + 1][j + 1] : INT_MAX;

                dp[i][j] = mat[i][j] + min({dLeft, dNext, dRight});
            }
        }

        return dp[0][col];

    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = INT_MAX;
        int n = mat.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));

        for(int j = 0;j < n;j++){
            ans = min(ans, solveTab(mat, j));
        }

        return ans;
    }
};
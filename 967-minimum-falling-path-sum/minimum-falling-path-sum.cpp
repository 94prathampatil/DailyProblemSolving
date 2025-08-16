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

    int minFallingPathSum(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = INT_MAX;
        int n = mat.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));

        for(int j = 0;j < n;j++){
            ans = min(ans, solve(0, j, n, mat, dp));
        }

        return ans;
    }
};
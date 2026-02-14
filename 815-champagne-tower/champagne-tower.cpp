class Solution {
public:
    double solve(int i, int j, int &poured, vector<vector<double>> &dp){
        if(i < j || i < 0 || j < 0)
            return 0.0;

        if(i == 0 && j == 0)
            return poured;

        if(dp[i][j] != -1) {
            return dp[i][j];
        } 

        double left = (solve(i - 1, j - 1, poured, dp) - 1) / 2.0;
        double right = (solve(i - 1, j, poured, dp) - 1) / 2.0;

        if(left < 0) left = 0;
        if(right < 0) right = 0;

        return dp[i][j] = left + right; 
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<double>> dp(101 + 1, vector<double> (101 + 1, -1));

        return min(1.0, solve(query_row, query_glass, poured, dp));
    }
};
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

    double solveTab(int &poured, int &query_row, int &query_glass){
        vector<vector<double>> dp(101, vector<double>(101, 0));

        dp[0][0] = poured;

        for(int i = 1; i <= query_row; i++){
            for(int j = 0; j <= i; j++){

                double val = 0;

                if(j - 1 >= 0){
                    double left = (dp[i - 1][j - 1] - 1) / 2.0;
                    if(left > 0) val += left;
                }

                if(j <= i - 1){
                    double right = (dp[i - 1][j] - 1) / 2.0;
                    if(right > 0) val += right;
                }

                dp[i][j] = val;
            }
        }

        return dp[query_row][query_glass];
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // vector<vector<double>> dp(101 + 1, vector<double> (101 + 1, -1));

        double ans = solveTab(poured, query_row, query_glass);
        return min(1.0, ans);
    }
};
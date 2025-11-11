class Solution {
public:
    int solve(int i, int m, int n, vector<int> &zero, vector<int> &one, vector<vector<vector<int>>> &dp){
        if(m < 0 || n < 0)  
            return -1e9;
            
        if(i == one.size())
            return 0;

        if(dp[i][m][n] != -1)
            return dp[i][m][n];

        int take = 1 + solve(i + 1, m - zero[i], n - one[i], zero, one, dp);
        int skip = solve(i + 1, m, n, zero, one, dp);

        return dp[i][m][n] = max(take, skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int len = strs.size();
        vector<int> one(len), zero(len);

        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>> (m + 1, vector<int>(n + 1, -1)));

        for(int i = 0;i < len;i++){
            for(int j = 0;j < strs[i].length();j++){
                (strs[i][j] == '0') ? 
                    zero[i]++ :
                    one[i]++;
            }
        }

        // for(int i = 0;i < len;i++){
        //     cout << "(" << one[i] <<", " << zero[i] << ") ";
        // }

        return solve(0, m, n, zero, one, dp);
    }
};
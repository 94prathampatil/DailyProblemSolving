class Solution {
public:
    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp){
        // Base case
        if(i == nums1.size()){
            if(j == 0){
                return -1e9;
            }
            return 0;
        }

        if(j == nums2.size())   return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        // 2 choice, 1 -> pick, 2 -> not pick

        int skip = solve(i + 1, j, nums1, nums2, dp);
        int pick = -1e9;
        for(int k = j;k < nums2.size();k++){
            pick = max(pick, (nums1[i] * nums2[k]) + solve(i + 1, k + 1, nums1, nums2, dp));
        }

        return dp[i][j] = max(skip, pick);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, -1));

        return solve(0, 0, nums1, nums2, dp);
    }
};
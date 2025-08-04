class Solution {
public:
    int solve(int index, vector<int>& nums, int n, vector<int> &dp){
        // base case
        if(index >= n - 1)  return 0;
        if(nums[index] == 0)    return INT_MAX;

        if(dp[index] != -1) return dp[index];

        int ans = INT_MAX;
        for(int step = 1;step <= nums[index];step++){
            if(step + index < n){
                int res = solve(step + index, nums, n, dp);
                if(res != INT_MAX){
                    ans = min(ans, 1 + res);
                }
            }
        }

        return dp[index] = ans;

        return ans;
    }
    int jump(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(0, nums, n, dp);
    }
};
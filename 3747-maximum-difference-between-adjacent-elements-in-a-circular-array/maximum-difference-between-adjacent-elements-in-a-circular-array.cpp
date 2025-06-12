class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = 0, n = nums.size();
    
        for(int i = 0;i < n - 1;i++){
            ans = max(ans, (abs(nums[i] - nums[i + 1])));
        }
        
        ans = max(ans, abs(nums[n - 1] - nums[0]));

        return ans;
    }
};
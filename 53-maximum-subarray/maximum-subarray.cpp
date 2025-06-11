class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = nums[0];
        int sum = 0;

        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            ans = max(sum, ans);

            if(sum < 0) sum = 0;
        }

        return ans;
    }
};
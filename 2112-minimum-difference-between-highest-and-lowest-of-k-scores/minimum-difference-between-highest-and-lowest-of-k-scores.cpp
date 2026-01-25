class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int mini = INT_MAX;
        int s = 0, e = k - 1;
        sort(nums.begin(), nums.end());
        if(nums.size() == 1) return 0;
        
        while(e < nums.size()){
            mini = min(mini, abs(nums[s++] - nums[e++]));
        }

        return mini;
    }
};
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        vector<int> preSum(n + 1);

        preSum[0] = 0;
        for(int i = 1;i < preSum.size();i++){
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        
        for(int i = 0;i < n;i++){
            int left = preSum[i];
            int right = preSum[n] - preSum[i + 1];

            if(left == right)   
                return i;
        }

        return -1;
    }
};
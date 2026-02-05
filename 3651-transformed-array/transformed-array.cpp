class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();

        vector<int> res(n, 0);

        for(int i = 0;i < n;i++){
            if(nums[i] > 0){
                int ind = (i + nums[i]) % n;
                res[i] = nums[ind];                   
            }
            else if(nums[i] < 0){
                int ind = ((i - abs(nums[i])) % n + n) % n;
                res[i] = nums[ind];
            }
            else{
                nums[i] = 0;
            }
        }

        return res;
    }
};
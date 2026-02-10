class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        int res = 0;

        for(int i = 0;i < n;i++){
            unordered_set<int> even, odd;

            for(int j = i;j < n;j++){
                if(!(nums[j] & 1)){
                    even.insert(nums[j]);
                }
                else{
                    odd.insert(nums[j]);
                }

                if(even.size() == odd.size())
                    res = max(res, j - i + 1);
            }
        }

        return res;
    }
};
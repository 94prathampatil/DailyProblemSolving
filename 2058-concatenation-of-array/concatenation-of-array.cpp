class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        vector<int> ans(2 * n, 0);

        for(int i = 0;i < n;i++){
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }

        return ans;
    }
};
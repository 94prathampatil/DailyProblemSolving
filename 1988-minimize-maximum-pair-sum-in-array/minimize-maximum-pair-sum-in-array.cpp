#define all(x) x.begin(), x.end()

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(all(nums));

        int i = 0, j = nums.size() - 1;
        int ans = INT_MIN;

        while(i < j){
            int sum = nums[i++] + nums[j--];
            ans = max(ans, sum);
        }

        return ans;
    }
};
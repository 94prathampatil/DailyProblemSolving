class Solution {
public:
    bool check(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int cnt = 0;

        for(int i = 1;i < nums.size();i++)
            if(nums[i] < nums[i - 1])   cnt++;

        if(nums[0] < nums[nums.size() - 1]) cnt++;

        return cnt <= 1;
    }
};
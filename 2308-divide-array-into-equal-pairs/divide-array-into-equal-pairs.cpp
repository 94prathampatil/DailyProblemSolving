class Solution {
public:
    bool divideArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(nums.begin(), nums.end());

        for(int i = 0;i < nums.size();i += 2){
            if(nums[i] != nums[i + 1]){
                return false;
            }
        }

        return true;
    }
};
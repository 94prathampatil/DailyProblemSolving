class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == 2){
                ans.push_back(-1);
                continue;
            }
            bool found = 0;

            for(int j = 0;j < 32;j++){
                if((nums[i] & (1 << j)) > 0)
                    continue;

                int prev = j - 1;
                int x = (nums[i] ^ (1 << (prev)));

                ans.push_back(x);
                found = 1;
                break;
            }

            if(!found)
                ans.push_back(-1);
        }

        return ans;
    }
};
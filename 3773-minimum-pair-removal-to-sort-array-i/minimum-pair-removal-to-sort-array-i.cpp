#define all(x) x.begin(), x.end()

class Solution {
public:
    int minSum(vector<int> &nums){        
        int mSum = INT_MAX;
        int index = -1;

        for(int i = 0;i < nums.size() - 1;i++){
            if(nums[i] + nums[i + 1] < mSum){
                index = i;
                mSum = nums[i] + nums[i + 1];
            }
        }

        return index;
    }
    int minimumPairRemoval(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int opr = 0;

        while(!is_sorted(all(nums))){
            int i = minSum(nums);

            nums[i] = nums[i] + nums[i + 1];

            nums.erase(nums.begin() + i + 1);

            opr++;
        }

        return opr;
    }
};
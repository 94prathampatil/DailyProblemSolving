class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 0);

        int ind = 0;
        for(auto &it:nums){
            if(it != 0){
                temp[ind] = it;
                ind++;
            }
        }

        nums = temp;
        return;
    }
};
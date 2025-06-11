class Solution {
public:
    void sortColors(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int s = 0, m = 0, e = nums.size() - 1;

        while(m <= e){
            if(nums[m] == 0){
                swap(nums[s++], nums[m++]);
            }
            else if(nums[m] == 2){
                swap(nums[m], nums[e--]);
            }
            else{
                m++;
            }
        }
    }
};
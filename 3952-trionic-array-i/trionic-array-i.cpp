class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        bool ans = false;
        if(n < 4)  return false;

        int i = 0;


        while(i + 1 < n && nums[i] < nums[i + 1])   i++;

        int p = i;
        if(p == 0)  return false;

        while(i + 1 < n && nums[i] > nums[i + 1])   i++;

        int q = i;
        if(q == n - 1 || q == p)    return false;

        while(i + 1 < n && nums[i] < nums[i + 1])   i++;


        return i == n - 1;

    }
};
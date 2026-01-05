class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> ans;
        int n = nums.size();

        unordered_map<int, int> mp;
        for(auto &i : nums)
            mp[i]++;

        for(int i = 1;i <= n;i++){
            if(mp.find(i) == mp.end())
                ans.push_back(i);
        }

        return ans;
    }
};
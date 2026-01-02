class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_set<int> s(nums.begin(), nums.end());
        int n = s.size();
        nums.insert(nums.end(), nums.begin(), nums.end());

        cout << n;

        unordered_map<int, int> mp;
        for (auto& i : nums)
            mp[i]++;

        for (auto& i : mp)
            if (i.second >= n)
                return i.first;

        return n;
    }
};
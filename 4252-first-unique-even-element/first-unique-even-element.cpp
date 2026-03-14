class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        map<int, int> mp;

        for(auto &i : nums){
            mp[i]++;
        }

        for(auto &i : nums){
            if(i % 2 == 0 && mp[i] == 1)
                return i;
        }

        return -1;
    }
};
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        map<int, int> mp;
        for(auto &i:nums){
            mp[i]++;
        }

        for(auto &i:mp){
            if(i.second % 2 != 0){
                return false;
            }
        }

        return true;
    }
};
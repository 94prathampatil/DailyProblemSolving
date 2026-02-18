class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<int, int> mp;
        for(auto &i : friends){
            mp[i]++;
        }

        vector<int> ans;
        for(auto &i : order){
            if(mp.count(i)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
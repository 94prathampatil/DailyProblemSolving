class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<int, int> mp;
        for(auto i:nums){
            mp[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto i:mp){
            pq.push({i.second, i.first});
            if((int)pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            ans.push_back(top.second);
        }

        return ans;
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        map<int, int> mp;

        for(auto &t : trips){
            int p = t[0], s = t[1], e = t[2];
            mp[s] += p;
            mp[e] -= p;
        }

        int passengers = 0;
        for(auto &i : mp){
            passengers += i.second;

            if(passengers > capacity){
                return false;
            }

            // cout << i.first << " " << i.second << endl;
        }

        return true;
    }
};
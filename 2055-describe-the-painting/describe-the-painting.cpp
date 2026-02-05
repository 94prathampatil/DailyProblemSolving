class Solution {
public:
    typedef long long ll;
    map<int, ll> mp;
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        for(auto &segment : segments){
            mp[segment[0]] += segment[2] * 1LL;
            mp[segment[1]] -= segment[2] * 1LL;
        }

        auto it = mp.begin();

        int start = it -> first;
        ll sum = it -> second;
        it++;

        vector<vector<ll>> res;

        while(it != mp.end()){
            if(sum > 0){
                res.push_back({start, it -> first, sum});
            }

            start = it -> first;
            sum += it -> second;

            it++;
        }

        return res;
    }
};
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> sortByBits(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<P> bit;

        for(auto &i : arr)
            bit.push_back({i, __builtin_popcount(i)});

        sort(bit.begin(), bit.end(), [](auto &p1, auto &p2){
            if(p1.second == p2.second)
                return p1.first < p2.first;
            return p1.second < p2.second;
        });

        vector<int> ans;
        for(auto &i : bit){
            ans.push_back(i.first);
        }


        return ans;
    }
};
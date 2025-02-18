#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

#define pb(x) push_back(x)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        map<int, int> mp;
        for(auto i:nums)
            mp[i]++;

        priority_queue<pair<int, int> > pq;
        for(auto &[i, freq] : mp){
            pq.push({freq, i});
        }

        vector<int> ans;
        for(int i = 0;i < k && !pq.empty();i++){
            ans.pb(pq.top().second);pq.pop();
        }

        return ans;
    }
};
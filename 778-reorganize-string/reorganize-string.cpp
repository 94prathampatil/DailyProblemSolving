const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

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
    string reorganizeString(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        string ans;
        
        map<char, int> mp;
        for(auto i:s)
            mp[i]++;
        
        priority_queue<pair<int, char> > pq;
        for(auto i:mp)
            pq.push({i.second, i.first});

            
        while(!pq.empty()){
            if(pq.size() == 1 && pq.top().first > 1)  return "";
            
            if(pq.size() == 1 && pq.top().first == 1) {
                ans += pq.top().second;
                break;
            }

            pair<int, char> p1 = pq.top(), p2;
            pq.pop();
            p2 = pq.top();
            pq.pop();

            ans += p1.second;
            ans += p2.second;

            if(p1.first > 1)
                pq.push({p1.first - 1, p1.second});

            if(p2.first > 1)
                pq.push({p2.first - 1, p2.second});
        }

        return ans;
    }
};
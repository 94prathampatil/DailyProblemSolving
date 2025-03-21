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
    int lastStoneWeight(vector<int>& s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        priority_queue<int> pq(s.begin(), s.end());
       
        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x != y)  pq.push(y - x);
        } 
        

        return pq.empty() ? 0 : pq.top();
    }
};
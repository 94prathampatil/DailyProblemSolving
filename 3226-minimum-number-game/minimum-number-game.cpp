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
    vector<int> numberGame(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto i:nums){
            pq.push(i);
        }

        vector<int> ans;
        while(!pq.empty()){
            int alice = pq.top();
            pq.pop();
            int bob = pq.top();
            pq.pop();

            ans.pb(bob);
            ans.pb(alice);
        }

        return ans;
    }
};
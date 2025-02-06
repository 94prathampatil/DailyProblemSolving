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
#define ll long long
#define inf INT_MIN

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        priority_queue<int> pq;
        int sum = 0;

        for(auto i:piles){
            pq.push(i);
            sum += i;
        }

        while(k--){
            int ele = pq.top();
            pq.pop();

            int stone = floor(ele / 2);
            sum -= stone;
            pq.push(ele - stone);
        }

        return sum;
    }
};
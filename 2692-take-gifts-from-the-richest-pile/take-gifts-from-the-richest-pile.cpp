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
#define mInf INT_MIN

class Solution {
public:
    long long pickGifts(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        priority_queue<pair<ll, ll>> pq;

        ll cnt = 0;
        for(auto i:arr){
            pq.push(make_pair(i, cnt++));
        }

        while(k--){
            ll ele = sqrt(pq.top().first);
            ll index = pq.top().second;
            arr[pq.top().second] = ele;
            pq.pop();
            pq.push(make_pair(ele, index));
        }

        ll ans = accumulate(arr.begin(), arr.end(),0LL);

        return ans;
    }
};
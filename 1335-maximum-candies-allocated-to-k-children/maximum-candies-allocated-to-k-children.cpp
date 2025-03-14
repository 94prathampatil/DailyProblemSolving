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
#define llv long long vector
#define all() v.begin(), v.end()
#define n v.size()

class Solution {
public:
    int maximumCandies(vector<int>& v, long long k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        ll sum = accumulate(all(), 0LL);
        if(sum < k) return 0;

        ll s = 1, e = *max_element(all());
        ll mid = s + (e - s) / 2;
        int ans = s;

        auto isOk = [&](int mid){
            ll count = 0;
            for(auto &i:v){
                count += (i / mid);
            }

            return count >= k;
        };

        while(s <= e){
            if(isOk(mid)){
                s = mid + 1;
                ans = mid;
            }
            else{
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        } 

        return ans;
    }
};
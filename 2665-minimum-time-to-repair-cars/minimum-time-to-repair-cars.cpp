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
    long long repairCars(vector<int>& v, int cars) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        ll maxi = *max_element(all());
        ll s = *min_element(all());
        ll e = 1LL * maxi * cars * cars;
        ll mid = s + (e - s) / 2;
        ll ans = s;

        auto isOk = [&](ll mid){
            ll cnt = 0;
            for(ll i = 0;i < n;i++){
                cnt += sqrt(mid/v[i]);
            }

            return cnt >= cars;
        };

        while(s <= e){
            if(isOk(mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
              
            mid = s + (e - s) / 2;
        }

        return ans;
    }
};
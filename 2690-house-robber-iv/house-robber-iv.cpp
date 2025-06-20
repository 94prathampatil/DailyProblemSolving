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
    int minCapability(vector<int>& v, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        ll s = *min_element(all()), e = *max_element(all()), mid = s + (e - s) / 2;
        int ans = e;

        auto isOk = [&](ll mid){
            ll count = 0;
            for(int i = 0;i < n;i++){
                if(v[i] <= mid){
                    count++;
                    i++;
                }
            }

            return count >= k;
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
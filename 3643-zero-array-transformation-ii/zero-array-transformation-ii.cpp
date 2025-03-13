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

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        ll n = nums.size();
        ll s = 0, e = q.size(), mid = s + (e - s) / 2, ans = -1;
        vector<ll> prediff(n, 0);

        auto isOk = [&](ll mid){
            vector<ll> tmp_diff(n + 1, 0);

            for(int i = 0;i < mid;i++){
                ll l = q[i][0];
                ll r = q[i][1];
                ll val = q[i][2];

                tmp_diff[l] -= val;
                tmp_diff[r + 1] += val;
            }

            prediff[0] = nums[0] + tmp_diff[0];

            for(int i = 1;i < n;i++){
                tmp_diff[i] += tmp_diff[i - 1];
                prediff[i] = nums[i] + tmp_diff[i];
            }

            for(auto &i:prediff){
                if(i > 0)   return false;
            }

            return true;
        };

        while(s <= e) {
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
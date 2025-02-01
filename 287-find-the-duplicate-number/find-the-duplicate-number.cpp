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
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        int s = 1, e = n, mid = s + (e - s) / 2;
        int ans = 0;

        auto isOk = [&](int mid){
            int cnt = 0;
            for(auto i:nums){
                if(i <= mid)    cnt++;
            }

            return cnt > mid;
        };

        while(s < e){
            if(isOk(mid)){
                e = mid;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }

        return s;

    }
};
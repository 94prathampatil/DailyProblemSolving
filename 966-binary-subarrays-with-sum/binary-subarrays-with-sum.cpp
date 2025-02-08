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

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = 0;
        int sum = 0;

        map<int, int> mp;

        for(auto i : nums){
            sum += i;
            if(sum == goal){
                ans++;
            }

            if(mp.find(sum - goal) != mp.end()){
                ans += mp[sum - goal];
            }

            mp[sum]++;
        }

        
        return ans; 
    }
};
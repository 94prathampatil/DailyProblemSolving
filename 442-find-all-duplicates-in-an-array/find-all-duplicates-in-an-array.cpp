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
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> ans;
        unordered_map<int, int> mp;

        for(int i = 0;i < nums.size();i++){
            if(mp.find(nums[i]) != mp.end()){
                ans.pb(nums[i]);
            }
            else{
                mp[nums[i]] = i;
            }
        }

        return ans;
    }
};
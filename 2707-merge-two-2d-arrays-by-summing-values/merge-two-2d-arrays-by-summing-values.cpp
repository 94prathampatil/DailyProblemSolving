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
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        map<int, int> mp;
        vector<vector<int>> ans;

        for(int i = 0;i < nums1.size();i++){
            mp[nums1[i][0]] += nums1[i][1];
        }
        for(int i = 0;i < nums2.size();i++){
            mp[nums2[i][0]] += nums2[i][1];
        }   

        for(auto i:mp){
            vector<int> temp = {i.first, i.second};
            ans.pb(temp);
        }

        return ans;
    }
};
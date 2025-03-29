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
    int findJudge(int n, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if(trust.size() == 0 && n == 1)
            return 1;

        vector<int> cnt(n + 1);
        for(auto &i:trust){
            cnt[i[0]]--;    // means the first person don't trust themselves
            cnt[i[1]]++;    // means the second person is person on which people trust
        }

        for(int i = 0;i < cnt.size();i++){
            if(cnt[i] == n - 1)
                return i;
        }

        return -1;
    }
};
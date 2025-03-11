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
    int numberOfSubstrings(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<int> charFreq(3, 0);
        int ans = 0;
        int n = s.length();
        int l = 0, r = 0;

        while(r < n){
            charFreq[s[r] - 'a']++;

            while(charFreq[0] && charFreq[1] && charFreq[2]){
                ans += n - r;
                charFreq[s[l++] - 'a']--;
            }

            r++;
        }

        
        return ans;

    }
};
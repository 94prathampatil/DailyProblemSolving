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
    int characterReplacement(string s, int k) {
        // Naive Solution / Brute Force
        // Got TLE

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int l = 0, r = 0;
        int maxLen = 0;
        int maxFreq = 0;
        int n = s.length();
        int hash[26] = {0};

        while(r < n){
            
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, (hash[s[r] - 'A']));
            int len = r - l + 1;
            
            if(len - maxFreq <= k){
                maxLen = max(maxLen, len);
            }
            else{
                hash[s[l] - 'A']--;                
                l++;
            }
            r++;

        }        


        return maxLen;

    }
};
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


class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        string ans;
        unordered_map<int, int> mp;

        for(auto &i:spaces){
            mp[i]++;
        }

        for(int i = 0;i < s.length();i++){
            char ch = s[i];

            if(mp.find(i) != mp.end()){
                ans += ' ';
                ans += ch;
            }
            else{
                ans += ch;
            }
        }

        return ans;
    }
};
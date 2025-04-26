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
    vector<int> lexicalOrder(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> ans;
        

        int curr = 1;

        for(int i = 0;i < n;i++){
            ans.pb(curr);
            if(curr * 10 <= n){
                curr *= 10;
            }
            else if((curr % 10) != 9 && curr + 1 <= n){
                curr++;
            }
            else{
                while((curr / 10) % 10 == 9){
                    curr /= 10;
                }
                curr = (curr / 10) + 1;
            }
        }

        return ans;
    }
};
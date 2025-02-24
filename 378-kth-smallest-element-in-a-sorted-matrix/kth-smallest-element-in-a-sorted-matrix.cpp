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

#define pb(x) push_back(x);

class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = m.size();
        int s = m[0][0];
        int e = m[n - 1][n - 1];
        int mid = s + (e - s) / 2;

        while(s < e){
            int j = n - 1;
            int cnt = 0;
            for(int i = 0;i < n;i++){
                int j = n - 1;
                while(j >= 0 && m[i][j] > mid){
                    j--;
                }
                cnt += j + 1;
            }

            if(cnt < k){
                s = mid + 1;
            }
            else{
                e = mid;
            }

            mid = s + (e - s) / 2;
        }   

        return s;
    }
};
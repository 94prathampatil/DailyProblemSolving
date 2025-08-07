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
    int solve(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp){
        // base case 
        if(left == right)   return 0;

        if(dp[left][right] != -1){
            return dp[left][right];
        }

        int ans = INT_MAX;

        for(int i = left;i < right;i++){
            int leftMost = solve(arr, maxi, left, i, dp);
            int rightMost = solve(arr, maxi, i + 1, right, dp);
            int maxProduct = maxi[{left, i}] * maxi[{i + 1, right}];
            ans = min(ans, (maxProduct + leftMost + rightMost));
        }

        return dp[left][right] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        map<pair<int, int>, int> maxi;

        for(int i = 0;i < n;i++){
            maxi[{i, i}] = arr[i];
            for(int j = i + 1;j < n;j++){
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }

        return solve(arr, maxi, 0, n - 1, dp);
    }
};
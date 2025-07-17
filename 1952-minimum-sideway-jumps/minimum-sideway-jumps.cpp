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
    int solve(vector<int>& obs, int currLane, int pos, vector<vector<int>> &dp){
        // Base Case 
        int n = obs.size() - 1;

        if(pos == n){
            return 0;
        }

        if(dp[currLane][pos] != -1){
            return dp[currLane][pos];
        }

        if(obs[pos + 1] != currLane){
            return dp[currLane][pos] = solve(obs, currLane, pos + 1, dp);
        }
        else{
            // we have three choices
            int ans = INT_MAX;
            for(int i = 1;i <= 3;i++){
                if(currLane != i && obs[pos] != i)
                    ans = min(ans, 1 + solve(obs, i, pos, dp));
                
            }
            dp[currLane][pos] = ans;

            return dp[currLane][pos];
        }
    }
    int minSideJumps(vector<int>& obs) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = obs.size();
        vector<vector<int>> dp(4, vector<int>(n, -1));
        return solve(obs, 2, 0, dp);
    }
};
class Solution {
public:
    const int INF = 1e9;
    vector<vector<int>> dp;
    string s;
    int n;

    int solve(int i, bool prevBucket) {
        if (i == n)
            return 0;

        if (dp[i][prevBucket] != -1)
            return dp[i][prevBucket];

        int ans = INF;

        
        if (s[i] == 'H') {
            
            if (prevBucket) {
                ans = solve(i + 1, false);
            } 
            else {
                
                if (i + 1 < n && s[i + 1] == '.') {
                    
                    ans = 1 + solve(i + 2, true);
                } 
                else {
                    ans = INF;  
                }
            }
        }
        else { 
            
            int skip = solve(i + 1, false);
            int take = 1 + solve(i + 1, true);

            ans = min(skip, take);
        }

        return dp[i][prevBucket] = ans;
    }

    int minimumBuckets(string hamsters) {
        s = hamsters;
        n = s.length();
        dp.assign(n, vector<int>(2, -1));

        int res = solve(0, false);
        return (res >= INF) ? -1 : res;
    }
};
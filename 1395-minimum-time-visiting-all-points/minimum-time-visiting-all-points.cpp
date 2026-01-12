class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = 0;
        for (int i = 1; i < p.size(); i++) {
            ans += max(
                abs(p[i][0] - p[i - 1][0]),
                abs(p[i][1] - p[i - 1][1])
            );
        }
        return ans;
    }
};
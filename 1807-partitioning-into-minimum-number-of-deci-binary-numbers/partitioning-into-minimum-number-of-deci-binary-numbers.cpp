class Solution {
public:
    int minPartitions(string n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = INT_MIN;

        for(int i = 0;i < n.length();i++){
            ans = max(ans, (n[i] - '0'));
        }

        return ans;
    }
};
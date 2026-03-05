class Solution {
public:
    int minOperations(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int cnt = 0, n = s.length();
        for(auto i = 0;i < n;i++)   cnt += (s[i] ^ i) & 1;

        return min(cnt, n - cnt);
    }
};
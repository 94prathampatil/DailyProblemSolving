class Solution {
public:
    int countBinarySubstrings(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int ans = 0;
        int prev = 0;
        int curr = 1;

        for(int i = 1;i < s.length();i++){
            if(s[i] == s[i - 1])
                curr++;
            else{
                ans += min(curr, prev);
                prev = curr;
                curr = 1;
            }
        }

        return ans + min(prev, curr);
    }
};
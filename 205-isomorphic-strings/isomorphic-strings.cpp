class Solution {
public:
    bool isIsomorphic(string s, string t) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<char, int> m;
        unordered_map<char, int> n;

        for(int i = 0;i < s.length();i++){
            m[s[i]] = i;
            n[t[i]] = i;
        }

        for(int i = 0;i < s.length();i++){
            if(m[s[i]] != n[t[i]]){
                return false;
            }
        }

        return true;

    }
};
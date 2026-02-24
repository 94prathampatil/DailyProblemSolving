class Solution {
public:
    bool hasAllCodes(string s, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = s.length();
        int p = (1 << k);
        unordered_set<string> st;

        for(int i = k;i <= n;i++){
            string sub = s.substr(i - k, k);

            if(!st.count(sub)){
                st.insert(sub);
                p--;
            }

            if(p == 0)  
                return true;
        }

        return false;
    }
};
class Solution {
public:
    string ans = "";
    void solve(int &n, int &k, string &s){
        if(ans != "")
            return;

        if(s.length() == n){
            k--;
            if(k == 0){
                ans = s;
            }
            return;
        }

        for(char ch = 'a';ch <= 'c';ch++){
            if(s.empty() || s.back() != ch){
                s += ch;
                solve(n, k, s);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        string s = "";
        solve(n, k, s);
        return ans;
    }
};
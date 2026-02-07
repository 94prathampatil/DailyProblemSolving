class Solution {
public:
    int minimumDeletions(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        stack<char> st;
        int cnt = 0;
        for(auto &ch : s){
            if(!st.empty() && ch == 'a' && st.top() == 'b'){
                st.pop();
                cnt++;
            }
            else{
                st.push(ch);
            }
        }

        return cnt;
    }
};
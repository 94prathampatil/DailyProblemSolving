class Solution {
public:
    string clearDigits(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        stack<char> st;

        for(auto i:s){
            if(i >= 'a' && i <= 'z'){
                st.push(i);
            }
            else{
                st.pop();
            }
        }

        string str = "";
        while(!st.empty()){
            str += st.top();
            st.pop();
        }

        reverse(str.begin(), str.end());

        return str;
    }
};
class Solution {
public:
    string answerString(string word, int nf) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if(nf == 1) return word;


        int n = word.size(), m = n - nf + 1;
        string res = "";
        for(int i = 0;i < n;++i){
            res = max(res, word.substr(i, m));         
        }

        return res;
    }
};
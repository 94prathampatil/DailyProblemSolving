class Solution {
public:
    int checkbalanced(vector<int> &freq){
        int common = 0;

        for(int i = 0;i < 26;i++){
            if(freq[i] == 0)    continue;
            if(common == 0)
                common = freq[i];
            else if(freq[i] != common)  
                return 0;
        }

        return 1;
    }
    int longestBalanced(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = s.length(), res = 0;

        for(int i = 0;i < n;i++){
            vector<int> freq(26, 0);
            for(int j = i;j < n;j++){
                freq[s[j] - 'a']++;

                if(checkbalanced(freq)){
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};
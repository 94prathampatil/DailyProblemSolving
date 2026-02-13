class Solution {
public:
    int helper(string &s, int ch1, int ch2){
        int n = s.length();

        unordered_map<int, int> mp;
        mp[0] = -1;   // fix 1

        int count1 = 0, count2 = 0;
        int maxL = 0;

        for(int i = 0;i < n;i++){
            if(s[i] != ch1 && s[i] != ch2){
                mp.clear();
                mp[0] = i;   // reset base
                count1 = 0;
                count2 = 0;
                continue;
            }

            if(s[i] == ch1) count1++;
            if(s[i] == ch2) count2++;

            int diff = count1 - count2;

            if(mp.count(diff)){
                maxL = max(maxL, i - mp[diff]);
            } else {
                mp[diff] = i;
            }
        }

        return maxL;
    }

    int longestBalanced(string s) {
        int maxL = 0, n = s.length();

        
        int count = 1;
        for(int i = 1;i < n;i++){
            if(s[i] == s[i - 1])
                count++;
            else{
                maxL = max(maxL, count);
                count = 1;
            }
        }
        maxL = max(maxL, count);

        
        maxL = max(maxL, helper(s, 'a', 'b'));
        maxL = max(maxL, helper(s, 'a', 'c'));
        maxL = max(maxL, helper(s, 'b', 'c'));

        
        int cntA = 0, cntB = 0, cntC = 0;

        unordered_map<string, int> mp;
        mp["0_0"] = -1;   

        for(int i = 0;i < n;i++){
            if(s[i] == 'a') cntA++;
            else if (s[i] == 'b') cntB++;
            else cntC++;

            int diffAB = cntA - cntB;
            int diffAC = cntA - cntC;

            string key = to_string(diffAB) + "_" + to_string(diffAC);

            if(mp.count(key)){
                maxL = max(maxL, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }

        return maxL;
    }
};
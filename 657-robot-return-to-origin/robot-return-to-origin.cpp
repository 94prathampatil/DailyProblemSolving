class Solution {
public:
    typedef pair<int, int> P;
    bool judgeCircle(string moves) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int i = 0, j = 0;
        unordered_map<char, P> mp;
        mp['L'] = {0, 1};
        mp['R'] = {0, -1};
        mp['D'] = {1, 0};
        mp['U'] = {-1, 0};

        for(auto move : moves){
            i += mp[move].first;
            j += mp[move].second; 
        }

        return (i == 0 && j == 0);
    }
};
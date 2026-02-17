class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<string> res;

        for(int H = 0;H <= 11;H++){
            for(int M = 0;M <= 59;M++){
                if(__builtin_popcount(H) + __builtin_popcount(M) == turnedOn){
                    string hour = to_string(H);
                    string min = ((M < 10) ? "0" : "") + to_string(M);

                    res.push_back(hour + ":" + min);
                }
            }
        }

        return res;
    }
};
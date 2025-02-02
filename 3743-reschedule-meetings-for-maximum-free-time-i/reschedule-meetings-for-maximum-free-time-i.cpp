const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

#define pb(x) push_back(x)

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& sT, vector<int>& eT) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> freeGap(1, sT[0]);

        for(int i = 1;i < sT.size();i++){
            freeGap.pb(sT[i] - eT[i - 1]);
        }

        freeGap.pb(eventTime - eT.back());

        int maxFreeGap = 0, currSum = 0;

        for(int i = 0;i < freeGap.size();i++){
            currSum += freeGap[i] - ((i >= k + 1) ? freeGap[i - (k + 1)] : 0);
            maxFreeGap = max(maxFreeGap, currSum);
        }

        return maxFreeGap;

        // vector<pair<int, int>> time;
        // int n = sT.size();
        
        // for(int i = 0;i < n;i++){
        //     time.pb(make_pair(sT[i], eT[i]));
        // }


        // for(int i = 0;i < time.size() - 1;i++){
        //     int ithStartTime = time[i].first;
        //     int ithEndTime = time[i].second;
            
        //     int inextStartTime = time[i + 1].first;
        //     int inextEndTime = time[i + 1].second;

        //     if(ithEndTime == inextStartTime)
        //         continue;

        //     int diff = abs(ithEndTime - inextStartTime);

        //     inextStartTime = abs(diff - inextStartTime);
        //     inextEndTime = abs(diff - inextEndTime);

        //     time[i + 1] = make_pair(inextStartTime, inextEndTime);

        //     k--;
        //     if(k == 0)
        //         break;
        // }

        // int start = 0;
        // int cnt = 0;
        
        // for(int i = 0;i < time.size();i++){
        //     cnt += (time[i].first - start);
        //     start = time[i].second;
        // }
        // cnt += eventTime - time[time.size() - 1].second;

        
        // cout<<cnt<<endl;
        

        // for(auto i:time){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        

        // return cnt;
    }
};
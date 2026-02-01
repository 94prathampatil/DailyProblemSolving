#define Sort(x) sort(x.begin(), x.end())

class Solution {
public:
    using pii = pair<int, int>;
    int maximumPopulation(vector<vector<int>>& logs) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<pii> events;
        for(auto &log : logs){
            events.push_back({log[0], 1});
            events.push_back({log[1], -1});
        }

        Sort(events);
        int currPop = 0, maxPop = 0, year = 0;

        for(auto &event : events){
            currPop += event.second;

            if(currPop > maxPop){
                maxPop = currPop;
                year = event.first;
            }
        }

        return year;
    }
};
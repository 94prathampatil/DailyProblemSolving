#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

class Solution {
public:
    int M = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        hFences.pb(1);
        vFences.pb(1);

        hFences.pb(m);
        vFences.pb(n);

        sort(all(hFences));
        sort(all(vFences));

        unordered_set<int> w;

        for(int i = 0;i < vFences.size();i++){
            for(int j = i + 1;j < vFences.size();j++){
                int width = vFences[j] - vFences[i];
                w.insert(width);
            }
        }


        int maxi = 0;
        for(int i = 0;i < hFences.size();i++){
            for(int j = i + 1;j < hFences.size();j++){
                int height = hFences[j] - hFences[i];
                if(w.find(height) != w.end())
                    maxi = max(maxi, height);
            }
        }


        return (maxi == 0) ? -1 : (1LL * maxi * maxi) % M;
    }
};
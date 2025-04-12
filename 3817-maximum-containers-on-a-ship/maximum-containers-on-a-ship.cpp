class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        n *= n;
        int cnt = 0, sum = 0;
        
        for(int i = 1;i <= n;i++){
            sum += w;
            if(sum <= maxWeight){
                cnt++;
            }
        }

        return cnt;
    }
};
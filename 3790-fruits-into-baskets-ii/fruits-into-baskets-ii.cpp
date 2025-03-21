class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = 0;
        for(int i = 0;i < fruits.size();i++){
            for(int j = 0;j < baskets.size();j++){
                if(baskets[j] >= fruits[i]){
                    baskets[j] = -1;
                    break;
                }
            }
        }

        for(auto &i:baskets){
            if(i != -1){
                ans++; 
            }
        }

        return ans;
    }
};
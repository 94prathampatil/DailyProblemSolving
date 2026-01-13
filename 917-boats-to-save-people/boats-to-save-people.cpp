#define all(x) x.begin(), x.end()

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(all(people));

        int n = people.size();
        int i = 0, j = n - 1, ans = 0;

        while(i <= j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;
            }
            else{
                j--;
            }
            ans++;
        }

        return ans;
    }
};
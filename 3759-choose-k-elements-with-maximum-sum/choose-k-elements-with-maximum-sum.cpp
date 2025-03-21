#define all() element.begin(), element.end()
#define ll long long

class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums1.size();

        vector<array<int, 3>> element(n);
        for(int i = 0;i < n;i++){
            element[i] = {nums1[i], nums2[i], i};
        }

        sort(all());
        vector<ll> ans(n);
        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum = 0;

        for(int i = 0;i < n;i++){
            if(i > 0 && element[i - 1][0] == element[i][0]){
                ans[element[i][2]] = ans[element[i - 1][2]];
            }
            else{
                ans[element[i][2]] = sum;
            }

            pq.push(element[i][1]);
            sum += element[i][1];

            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
        }

        return ans;
    }
};
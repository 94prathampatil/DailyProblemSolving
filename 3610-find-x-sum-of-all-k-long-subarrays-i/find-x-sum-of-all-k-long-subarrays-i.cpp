class Solution {
public:
    int xSum(const vector<int> &nums, int s, int e, int x) {
        unordered_map<int,int> freq;
        for (int i = s; i <= e; ++i) freq[nums[i]]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (auto &p : freq) {
            pq.push({p.second, p.first}); 
            if ((int)pq.size() > x) pq.pop();
        }

        int ans = 0;
        while (!pq.empty()) {
            auto pr = pq.top(); pq.pop();
            ans += pr.first * pr.second; 
        }
        return ans;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        
        for (int i = 0; i <= n - k; ++i) {
            ans.push_back(xSum(nums, i, i + k - 1, x));
        }
        return ans;
    }
};

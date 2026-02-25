auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    typedef long long ll;
    void updateTree(int i, int l, int r, int idx, vector<ll> &segmentTree){
        if(l == r){
            segmentTree[i] = 1;
            return;
        }

        int mid = l + (r - l) / 2;

        if(idx <= mid){
            updateTree(2 * i + 1, l, mid, idx, segmentTree);
        }
        else{
            updateTree(2 * i + 2, mid + 1, r, idx, segmentTree);
        }

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];

        return;
    }

    ll queryTree(int s, int e, int i, int l, int r, vector<ll> &segmentTree){
        if(r < s || l > e)  return 0;

        if(l >= s && r <= e)
            return segmentTree[i];

        int mid = l + (r - l) / 2;
        
        ll left = queryTree(s, e, 2 * i + 1, l, mid, segmentTree);
        ll right = queryTree(s, e, 2 * i + 2, mid + 1, r, segmentTree);

        return left + right;
    }
    
    ll goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums1.size();
        unordered_map<int, int> mp;

        for(int i = 0;i < n;i++){
            mp[nums2[i]] = i;
        }

        vector<ll> segmentTree(4 * n);
        ll res = 0;

        updateTree(0, 0, n - 1, mp[nums1[0]], segmentTree);

        for(int i = 1;i < n;i++){
            int idx = mp[nums1[i]];

            ll leftCommonCount    = queryTree(0, idx, 0, 0, n - 1, segmentTree);
            ll leftNotCommonNums2 = i - leftCommonCount;

            ll afterIndexIdx    = (n - 1) - idx;
            ll rightCommonCount = afterIndexIdx - leftNotCommonNums2;

            res += leftCommonCount * rightCommonCount;

            updateTree(0, 0, n - 1, idx, segmentTree);            
        }

        return res;
    }
};
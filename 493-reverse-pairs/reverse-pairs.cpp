#define pb push_back

class Solution {
    void mergeArray(vector<int>& nums, int s, int mid, int e) {
        vector<int> temp;
        int l = s;
        int r = mid + 1;

        while (l <= mid && r <= e) {
            if (nums[l] <= nums[r]) {
                temp.pb(nums[l++]);
            } else {
                temp.pb(nums[r++]);
            }
        }

        while (l <= mid) {
            temp.pb(nums[l++]);
        }

        while (r <= e) {
            temp.pb(nums[r++]);
        }

        for (int i = s; i <= e; i++) {
            nums[i] = temp[i - s];
        }
    }

    int countPair(vector<int>& nums, int s, int mid, int e) {
        int right = mid + 1;
        int count = 0;

        for (int i = s; i <= mid; i++) {
            while (right <= e && (long long)nums[i] > 2LL * nums[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }
        return count;
    }

    void mergeSort(vector<int>& nums, int s, int e, int& cnt) {
        if (s >= e) return;
        int mid = s + (e - s) / 2;

        mergeSort(nums, s, mid, cnt);
        mergeSort(nums, mid + 1, e, cnt);
        cnt += countPair(nums, s, mid, e);
        mergeArray(nums, s, mid, e);
    }

public:
    int reversePairs(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int cnt = 0;
        mergeSort(nums, 0, nums.size() - 1, cnt);
        return cnt;
    }
};

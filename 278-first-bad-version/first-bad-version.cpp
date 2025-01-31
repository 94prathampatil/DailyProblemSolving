// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int s = 1, e = n, mid = s + (e - s) / 2;
        int ans = 0;

        while(s <= e){
            if(isBadVersion(mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }

            mid = s + (e - s) / 2;
        }

        return ans;
    }
};
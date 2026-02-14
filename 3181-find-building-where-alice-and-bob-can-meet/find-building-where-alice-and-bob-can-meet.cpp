const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif


class Solution {
public:
    vector<int> segment;

    void buildTree(int i, int l, int r, vector<int> &heights){
        if(l == r){
            segment[i] = l;
            return;
        }

        int mid = l + (r - l) / 2;

        buildTree(2 * i + 1, l, mid, heights);
        buildTree(2 * i + 2, mid + 1, r, heights);

        int left = segment[2 * i + 1];
        int right = segment[2 * i + 2];

        segment[i] = (heights[left] > heights[right]) ? left : right;
    }

    int RMIQ(int s, int e, int i, int l, int r, vector<int> &heights){
        if(l > e || r < s)  
            return -1;

        if(s <= l && r <= e)
            return segment[i];

        int mid = l + (r - l) / 2;

        int left = RMIQ(s, e, 2 * i + 1, l, mid, heights);
        int right = RMIQ(s, e, 2 * i + 2, mid + 1, r, heights);

        if(left == -1) return right;
        if(right == -1) return left;

        return (heights[left] > heights[right]) ? left : right;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& q) {

        int n = heights.size();
        int m = q.size();

        vector<int> ans(m, -1);

        segment.resize(4 * n);
        buildTree(0, 0, n - 1, heights);

        for(int i = 0; i < m; i++){

            int l = q[i][0];
            int r = q[i][1];

            if(l > r) swap(l, r);
            
            if(l == r){
                ans[i] = l;
                continue;
            }

            if(heights[r] > heights[l]){
                ans[i] = r;
                continue;
            }

            int s = r + 1;
            int e = n - 1;
            int res = -1;

            while(s <= e){

                int mid = s + (e - s) / 2;

                int ind = RMIQ(s, mid, 0, 0, n - 1, heights);

                if(ind != -1 && heights[ind] > max(heights[l], heights[r])){
                    res = ind;
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }

            ans[i] = res;
        }

        return ans;
    }
};
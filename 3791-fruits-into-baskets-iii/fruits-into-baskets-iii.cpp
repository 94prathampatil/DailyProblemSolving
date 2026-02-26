class Solution {
public:
    void buildTree(int i, int l, int r, vector<int> &segment, vector<int>& baskets){
        if(l == r){
            segment[i] = baskets[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildTree(2 * i + 1, l, mid, segment, baskets);
        buildTree(2 * i + 2, mid + 1, r, segment, baskets);

        segment[i] = max(segment[2 * i + 1], segment[2 * i + 2]);

        return;
    }

    bool query(int i, int l, int r, vector<int> &segment, int fruit){
        if(segment[i] < fruit)  return false;

        if(l == r){
            segment[i] = -1;
            return true;
        }

        int mid = l + (r - l) / 2;

        bool placed = false;

        if(segment[2 * i + 1] >= fruit){
            placed = query(2 * i + 1, l, mid, segment, fruit);
        }
        else{
            placed = query(2 * i + 2, mid + 1, r, segment, fruit);
        }

        segment[i] = max(segment[2 * i + 1], segment[2 * i + 2]);

        return placed;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        
        int unplaced = 0;
        vector<int> segment(4 * n, -1);
        buildTree(0, 0, n - 1, segment, baskets);

        for(auto &fruit : fruits){
            if(query(0, 0, n - 1, segment, fruit) == false)
                unplaced++;
        }

        return unplaced;
    }
};
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return false;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }

        return true;
    }
};


class Solution {
public:

    bool check(int n, vector<vector<int>>& edges, int k, int stability) {

        DSU dsu(n);
        int countUpgrades = 0;

        vector<vector<int>> upgradeCandidates; // {strength, u, v}

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int s = e[2];
            int must = e[3];

            if (must == 1) {

                if (s < stability)
                    return false;

                dsu.Union(u, v);
            }
            else {

                if (s >= stability) {
                    dsu.Union(u, v);
                }
                else if (2 * s >= stability) {
                    upgradeCandidates.push_back({2 * s, u, v});
                }
            }
        }

        for (auto &edge : upgradeCandidates) {

            int u = edge[1];
            int v = edge[2];

            if (dsu.find(u) != dsu.find(v)) {

                if (countUpgrades >= k)
                    return false;

                dsu.Union(u, v);
                countUpgrades++;
            }
        }

        int root = dsu.find(0);

        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != root)
                return false;
        }

        return true;
    }


    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int l = 1, r = 2*1e5;

        DSU dsu(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int s = edge[2];
            int m = edge[3];

            if (m == 1) { //must be included in spanning tree
                if(dsu.Union(u, v) == false)
                    //edge creates a cycle (both nodes already belong to the same component).
                    //For example : input is a cycle with all edge having m = 1
                    return -1;
            }
        }

        int result = -1;

        while (l <= r) {

            int mid = (l + r) / 2;

            if (check(n, edges, k, mid)) {
                result = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return result;
    }
};
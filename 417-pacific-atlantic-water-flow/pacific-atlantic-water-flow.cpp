class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>> &heights, int type){
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> vis(n, vector(m, 0));
        queue<pair<int, int>> q;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(type == 0 && (i == 0 || j == 0)){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
                if(type == 1 && (i == n - 1 || j == m - 1)){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0;i < 4;i++){
                int x = r + dRow[i];
                int y = c + dCol[i];

                if(x >= 0 && y >= 0 && x <= n - 1 && y <= m - 1 && !vis[x][y] && heights[x][y] >= heights[r][c]){
                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }

        return vis;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> vis1 = solve(heights, 0);
        vector<vector<int>> vis2 = solve(heights, 1);
        vector<vector<int>> ans; 

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(vis1[i][j] == 1 && vis2[i][j] == 1) ans.push_back({i, j});
            }
        }

        return ans;
    }
};
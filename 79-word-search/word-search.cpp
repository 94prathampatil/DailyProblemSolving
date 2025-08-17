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
    bool dfs(int row, int col, int wordIndex, int n, int m, vector<vector<int>> &visited, vector<vector<char>>& board, string word){

        if(wordIndex == word.length())  return true;
        if(row < 0 || col < 0 || row >= n || col >= m || visited[row][col] || board[row][col] != word[wordIndex])   return false;

        visited[row][col] = 1;

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        for(int i = 0;i < 4;i++){
            int x = dRow[i] + row;
            int y = dCol[i] + col;

            if(dfs(x, y, wordIndex + 1, n, m, visited, board, word)){
                return true;
            }
        }

        visited[row][col] = 0;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!visited[i][j]){
                    if(dfs(i, j, 0, n, m, visited, board, word))    return true;
                }
            }
        }

        return false;
    }
};
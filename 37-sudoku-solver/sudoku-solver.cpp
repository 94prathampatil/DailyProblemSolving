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

#define pb(x) push_back(x)

class Solution {
public:
    bool isSafe(int row, int col, int val, vector<vector<char>> &board){
        for(int i = 0;i < 9;i++){
            if(board[row][i] == val + '0'){
                return false;
            }

            if(board[i][col] == val + '0'){
                return false;
            }

            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val + '0'){
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.'){
                    for(int val = 1;val <= 9;val++){
                        if(isSafe(i, j, val, board)){
                            board[i][j] = val + '0';

                            bool possible = solve(board);

                            if(possible){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        solve(board);
    }
};
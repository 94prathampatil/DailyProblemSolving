class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        for(int i = 0; i < 9; i++){
            vector<int> row(10, 0), col(10, 0), box(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    if(row[num]++) return false;
                }
                if(board[j][i] != '.'){
                    int num = board[j][i] - '0';
                    if(col[num]++) return false;
                }
                int r = 3*(i/3) + j/3;
                int c = 3*(i%3) + j%3;
                if(board[r][c] != '.'){
                    int num = board[r][c] - '0';
                    if(box[num]++) return false;
                }
            }
        }
        return true;
    }
};

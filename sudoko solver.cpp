class Solution {
public:

    bool isSafe(int row, int col, char num,
                vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {

            // check row
            if(board[row][i] == num)
                return false;

            // check column
            if(board[i][col] == num)
                return false;

            // check 3x3 box
            if(board[3 * (row / 3) + i / 3]
                    [3 * (col / 3) + i % 3] == num)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for(int row = 0; row < 9; row++) {

            for(int col = 0; col < 9; col++) {

                if(board[row][col] == '.') {

                    for(char num = '1'; num <= '9'; num++) {

                        if(isSafe(row, col, num, board)) {

                            board[row][col] = num;

                            if(solve(board))
                                return true;

                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

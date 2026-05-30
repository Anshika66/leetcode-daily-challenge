class Solution {
public:
    bool find(int i, int j, string& word, int idx,
              int m, int n, vector<vector<char>>& board) {

        if(i < 0 || j < 0 || i >= m || j >= n ||
           board[i][j] == '$') {
            return false;
        }

        if(board[i][j] != word[idx]) {
            return false;
        }

        if(idx == word.length() - 1) {
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        bool found =
            find(i + 1, j, word, idx + 1, m, n, board) ||
            find(i - 1, j, word, idx + 1, m, n, board) ||
            find(i, j + 1, word, idx + 1, m, n, board) ||
            find(i, j - 1, word, idx + 1, m, n, board);

        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == word[0] &&
                   find(i, j, word, 0, m, n, board)) {
                    return true;
                }
            }
        }

        return false;
    }
};

class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int r, int c, int n, int m) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }

    void dfs(vector<vector<char>>& grid, int row, int col, int n, int m,
             vector<vector<bool>>& vis) {

        vis[row][col] = true;

        for (int k = 0; k < 4; k++) {
            int r = row + x[k];
            int c = col + y[k];

            if (valid(r, c, n, m) && grid[r][c] == '1' && !vis[r][c]) {
                dfs(grid, r, c, n, m, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(grid, i, j, n, m, vis);
                    res++;
                }
            }
        }

        return res;
    }
};
class Solution {
public:
    bool safe(int node, int n, int m,
              vector<vector<int>> &edges,
              int color[], int col) {

        for(int k = 0; k < n; k++) {
            if(k != node &&
               edges[node][k] == 1 &&
               color[k] == col) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int n, int m,
               vector<vector<int>> &edges,
               int color[]) {

        if(node == n) {
            return true;
        }

        for(int i = 1; i <= m; i++) {

            if(safe(node, n, m, edges, color, i)) {

                color[node] = i;

                if(solve(node + 1, n, m, edges, color))
                    return true;

                color[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(int v,
                       vector<vector<int>> &edges,
                       int m) {

        vector<vector<int>> graph(v, vector<int>(v, 0));

        for(auto &e : edges) {
            int u = e[0];
            int w = e[1];

            graph[u][w] = 1;
            graph[w][u] = 1;
        }

        int color[v];
        memset(color, 0, sizeof(color));

        return solve(0, v, m, graph, color);
    }
};

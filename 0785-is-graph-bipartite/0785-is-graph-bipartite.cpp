class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, 
             vector<int>& colors, int c) {
        
        colors[node] = c;

        for (int neigh : graph[node]) {
            if (colors[neigh] == c) {
                return false;
            }
           
            if (colors[neigh] == -1) {
                if (!dfs(graph, neigh, colors, 1 - c)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> colors(n, -1);

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (!dfs(graph, i, colors, 0)) {
                    return false;
                }
            }
        }

        return true;
    }
};
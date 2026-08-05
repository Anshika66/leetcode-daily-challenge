class Solution {
public:
    bool cycle = false;

    void dfs(vector<vector<int>>& adj, int node,
             vector<bool>& vis, vector<bool>& path) {

        vis[node] = true;
        path[node] = true;

        for (int i = 0; i < adj[node].size(); i++) {
            int neigh = adj[node][i];

            if (vis[neigh] && path[neigh]) {
                cycle = true;
                return;
            }

            if (!vis[neigh]) {
                dfs(adj, neigh, vis, path);

                if (cycle)
                    return;
            }
        }

        path[node] = false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {

        int E = edges.size();

        vector<vector<int>> adj(V);

        
        for (int i = 0; i < E; i++) {
            int src = edges[i][0];
            int dest = edges[i][1];

            adj[src].push_back(dest);
        }

        vector<bool> vis(V, false);
        vector<bool> path(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(adj, i, vis, path);

                if (cycle)
                    return true;
            }
        }

        return false;
    }
};

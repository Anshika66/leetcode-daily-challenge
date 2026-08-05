class Solution {
  public:
    bool cycle = false;
    
    void dfs(vector<vector<int>>&adj  , int node , int parent , vector<bool>&vis){
        vis[node] = 1;
        
        for(int i = 0 ; i < adj[node].size(); i++){
            int neigh = adj[node][i];
            
            if(vis[neigh] == 1 && neigh != parent){
                cycle = true;
                return ; 
            }
            
            if(vis[neigh] == 0){
                dfs(adj , neigh, node , vis);
                if(cycle) return ;
            }
        }
        return ; 
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V) ;
        
        int n = edges.size();
     
        for(int i = 0 ; i <n ; i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        
        vector<bool> vis(V , 0);
        
        for(int i = 0 ; i < V ; i++){
            if(vis[i] == 0){
                dfs(adj ,  i , -1 , vis);
                if(cycle) return true;
            }
        }
        
        return false;
        
    }
};

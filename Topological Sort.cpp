class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        int n = edges.size();
        vector<int>indegree(V , 0);
        
        for(int i = 0 ; i < n ; i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            
            adj[src].push_back(dest);
            indegree[dest]++;
        }
        
        queue<int>q;
        
        for(int i = 0 ; i < V ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int>res; 
        while(!q.empty()){
            int a = q.front();
            q.pop();
            
            res.push_back(a);
            
            for(int i = 0 ; i < adj[a].size(); i++){
                int neigh = adj[a][i];
                indegree[neigh]--;
                
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        
        
        return res;
        
        
        
    }
};

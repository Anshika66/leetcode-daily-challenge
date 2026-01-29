class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF = 1e9;
        const int N = 26;  
        
        
        vector<vector<long long>> dist(N, vector<long long>(N, INF));
        
        for (int i = 0; i < N; i++) {
            dist[i][i] = 0;
        }
        
        int m = original.size();
        for (int i = 0; i < m; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
           
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        
       
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        long long totalCost = 0;
        int n = source.size();
        
        for (int i = 0; i < n; i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            
            if (u == v) continue;  
            
            if (dist[u][v] >= INF) {
                return -1;  
            }
            
            totalCost += dist[u][v];
        }
        
        return totalCost;
    }
};

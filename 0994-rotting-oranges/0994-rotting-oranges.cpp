class Solution {
public:
    int x[4] = {-1 , 1 , 0 , 0};
    int y[4] = {0 , 0 , -1 , 1};

    bool valid(int i  , int j , int n , int m){
        if(i < 0 || i >= n || j < 0 || j >= m){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;

        queue<pair<int , int>> q;
        int fresh = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                    grid[i][j] = -1;
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while(!q.empty() && fresh > 0){
            time++;
            int s = q.size();

            while(s--){
                pair<int ,int> t = q.front();
                q.pop();

                for(int k = 0 ; k < 4 ; k++){
                    int r = t.first + x[k];
                    int c = t.second + y[k];

                    if(valid(r , c , n , m) && grid[r][c] == 1){
                        q.push({r , c});
                        grid[r][c] = -1;
                        fresh--;
                    }
                }
            }
        }
        if(fresh > 0){
            return -1;
        }
        return time;
    };
};
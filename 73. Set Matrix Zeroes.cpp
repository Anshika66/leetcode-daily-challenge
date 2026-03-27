class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     vector<pair<int , int>> arr;

    //     for(int i = 0;i<m ; i++){
    //         for(int  j = 0; j< n ;j++){
    //             if(matrix[i][j] == 0){
    //                 arr.push_back({i , j});
    //             }
    //         }
    //     }

    //     int x  = arr.size();

    //     for(int  a = 0; a < x ; a++){
    //         int row = arr[a].first;
    //         int col  = arr[a].second;
            

    //         for(int i = 0 ; i< m ; i++){
    //             matrix[i][col] = 0;
    //         }

    //         for(int  j = 0; j<n ; j++){
    //             matrix[row][j] = 0;
    //         }
    //     } 

        int m = matrix.size();
        int n = matrix[0].size();
        // vector<int> row(m, 0);  --> matrix[..][0] 
        // vector<int> col(n, 0);  --> matrix[0][..]

        // for(int i = 0;i<m ; i++){
        //     for(int j = 0;j<n ; j++){
        //         if(matrix[i][j] == 0){
        //             row[i] = 1;
        //             col[j] = 1;
        //         }
        //     }
        // }

        // for(int i = 0;i<m ; i++){
        //     for(int j = 0;j<n ; j++){
        //         if(row[i] == 1 || col[j] == 1){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        int col0 = 1;

        for(int i = 0;i<m ; i++){
            for(int j = 0;j<n ; j++){
                if(matrix[i][j] == 0){
                    //mark the i-th row 
                    matrix[i][0] = 0;
                    //mark the j-th col 
                    if(j != 0){
                        matrix[0][j] = 0;
                    }
                    else{
                        col0 = 0;
                    }
                }
            }
        }

        for(int i = 1 ; i< m ; i++){
            for(int j = 1 ; j< n ; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int j = 0 ; j<n ; j++){
                matrix[0][j] = 0;
            }
        }

        if(col0 == 0){
            for(int i = 0 ; i< m ; i++){
                matrix[i][0] = 0;
            }
        }

    }
};

class Solution {
public:
    // int solve(vector<int>& cost , int i , vector<int>&dp){
    //     int n = cost.size()-1;
    //     if(i == n){
    //         return cost[n];
    //     }
    //     if(i > n){
    //         return 0;
    //     }
    //     if(dp[i] != -1){
    //         return dp[i];
    //     }

    //     dp[i] =  cost[i] + min(solve(cost , i+1 , dp) , solve(cost , i+2 , dp));
    //     return dp[i];

    // }

    int solve(vector<int>&cost , int n){
        vector<int> dp(n+1 , 0);
        dp[0] = cost[0] ; 
        dp[1] = cost[1];

        for(int i = 2 ; i < n  ; i++){
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2
            ]);
        }
        return min(dp[n-1] , dp[n-2]);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n+1 , -1);
        // return min(solve(cost , 0 , dp) , solve(cost , 1,dp)); 
        return solve(cost, n);
    }
};
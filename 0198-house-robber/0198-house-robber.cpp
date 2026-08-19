class Solution {
public:
    int solve(vector<int>& nums , int n , int index , int money , vector<int>&dp){
        if(index >= n){
            return 0;
        }
        //step 2 
        if(dp[index] != -1){
            return dp[index];
        }

        int inc = nums[index] + solve(nums, n, index + 2, money,dp);
        int exc = solve(nums, n, index + 1, money,dp);

        dp[index] = max(inc, exc);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1 , -1);
        int ans = solve(nums , n , 0 , 0 , dp);
        return ans ; 
        
    }
};
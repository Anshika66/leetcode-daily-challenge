class Solution {
public:

    void solve(int idx , vector<int>& arr,int target ,int sum ,        vector<vector<int>>&ans,
        vector<int>&diary, int n){
            if(idx == n){
                if(sum == target){
                    ans.push_back(diary);
                    
                }
                return ;
            }

            solve(idx+1 , arr , target , sum , ans , diary , n);
            if(arr[idx]+sum <= target){
                diary.push_back(arr[idx]);
                sum = sum+arr[idx];
                solve(idx , arr , target , sum , ans , diary , n);
                diary.pop_back();
                sum = sum-arr[idx];
            }
        }

    vector<vector<int>> combinationSum(vector<int>& candidates,int target) {
        int n = candidates.size();

        vector<vector<int>>ans; 
        vector<int>diary;

        solve(0 , candidates , target , 0 , ans , diary , n);
        return ans ;

    }
};
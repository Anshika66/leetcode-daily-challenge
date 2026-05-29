class Solution {
  public:
    void findsum(int index , vector<int>nums , vector<int>&ans, int sum ){
        if(index == nums.size()){
            ans.push_back(sum);
            return ;
        }

        findsum(index+1 , nums , ans , sum+nums[index]);
        findsum(index+1  , nums , ans , sum);
    }
    vector<int> subsetSums(vector<int>& nums) {
        vector<int>ans ; 
        findsum(0 , nums , ans , 0);
        return ans ; 
    }
};

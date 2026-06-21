class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        

        int i = -1;

        vector<int>ans;
        

        while(low <= high){
            int guess = (low+high)/2;
            if(nums[guess] >= target){
                if(nums[guess] == target)
                    i = guess;
                high = guess-1;
            }
            else{
                low = guess+1;
            }
        }
        ans.push_back(i);

        int j = -1;
        low = 0;
        high = nums.size()-1;
        while(low <= high){
            int guess = (low+high)/2;

            if(nums[guess] <= target){
                if(nums[guess] == target){
                    j = guess;
                }
                low = guess +1 ;
            }
            else{
                high = guess-1;
            }
        }  
        ans.push_back(j);

        return ans;
    }
};

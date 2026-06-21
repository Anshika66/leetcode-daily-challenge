class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int n = nums.size();
        int ans = 0;

        while(low<= high){
            int guess = (low+high)/2;

            if(nums[guess] > nums[n-1]){
                low = guess+1;
            }else{
                ans = nums[guess];
                high = guess-1;
            }
        }
        return ans;
        
    }
};

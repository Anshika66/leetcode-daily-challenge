class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0 ;
        int j = n-1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int left  = -1;
        int right = -1 ;

        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi , nums[i]);
            if(maxi > nums[i]){
                right = i;
            }
        }

        for(int i = n-1 ; i >= 0 ; i--){
            mini = min(mini , nums[i]);
            if(mini < nums[i]){
                left = i;
            }
        }

        if(left == -1){
            return 0;
        }

        return right - left +1 ;
    }
};
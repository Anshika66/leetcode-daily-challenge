class Solution {
public:
    int maxElement(vector<int>& nums){
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0;i<n ; i++){
            maxi = max(maxi , nums[i]);
        }
        return maxi;
    }

    bool possible(vector<int>& nums , int threshold , int mid){
        int total = 0;
        int n = nums.size();
        for(int i = 0;i <n ;i++){
            total += ceil((double) nums[i] / mid);
        }

        if(total <= threshold){
            return true;
        }else{
            return false ;
        }

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1;
        int high = maxElement(nums);

        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;

            if(possible(nums , threshold , mid) == true){
                ans = mid;
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return ans;

     
    }
};

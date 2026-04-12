class Solution {
public:
    int maxElement(vector<int>&nums , int n){
        int maxi = INT_MIN;
        for(int i = 0;i<n ; i++){
            maxi = max(maxi , nums[i]);
        }
        return maxi;
    }
    int Sum(vector<int>&nums , int n){
        int sum = 0;
        for(int i = 0;i<n ; i++){
            sum += nums[i];
        }
        return sum;
    }
    int totalSub(vector<int>&nums , int n , int mid){
        int cntsub = 1 ; 
        int currentsum = 0;
        for(int i = 0;i<n ; i++){
            if(nums[i] + currentsum <= mid){
                currentsum += nums[i];
            }else{
                cntsub++;
                currentsum = nums[i];
            }
        }
        return cntsub;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = maxElement(nums  , n);
        int high = Sum(nums , n );

        while(low <= high){
            int mid = (low+high) / 2;
            int noOfSub = totalSub(nums, n , mid);

            if(noOfSub > k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
        
    }
};

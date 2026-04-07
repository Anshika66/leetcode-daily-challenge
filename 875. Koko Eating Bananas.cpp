class Solution {
public:
    int maxElement(vector<int>&piles){
        int n = piles.size();
        int maxi = INT_MIN;
        for(int i = 0;i< n ; i++){
            maxi = max(maxi , piles[i]);
        }
        return maxi;
    }

    long long requiredTime(vector<int>&piles , int mid){
        long long totalM = 0;
        int n = piles.size();
        for(int i = 0;i<n ; i++){
            totalM += ceil((double)piles[i]/mid);
        }
        return totalM;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n  = piles.size();
        int low = 1;
        int high = maxElement(piles);
        int ans = INT_MAX;

        while(low <= high){
            int mid = (low+high)/2;

            long long  totalhrs =  requiredTime(piles  , mid);

            if(totalhrs <= h){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans ;
        
    }
};

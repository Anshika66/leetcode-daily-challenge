class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        
        int ans = 0;
        while(low <= high){
            int mid = (low+high)/2;

            long long hrs = 0;

            for(int i = 0;i<n;i++){
                hrs += piles[i]/mid;
                if(piles[i] % mid != 0){
                    hrs += 1;
                }
            }
            if(hrs > h){
                low = mid+1;
            }else{
                ans = mid;
                high = mid-1;
            }
        }

        return ans ;
    }
};
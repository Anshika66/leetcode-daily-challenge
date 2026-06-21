class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int low = 0 ;
        int high = arr.size() -1;
        int i = -1;
        
        while(low <= high){
            int guess = (low+high)/2;
            if(arr[guess] >= target){
                if(arr[guess] == target){
                    i = guess;
                }
                high = guess-1;
            }else{
                low = guess+1;
            }
        }
        if(i == -1){
            return 0;
        }
        
        low = 0;
        high = arr.size()-1;
        int j = -1;
        while(low<=high){
            int guess = (low + high)/2;
            if(arr[guess] <= target){
                if(arr[guess] == target){
                    j = guess;
                }
                low = guess+1;
            }else{
                high = guess-1;
            }
        }
        
        int ans = j-i+1;
        return ans;

    }
};

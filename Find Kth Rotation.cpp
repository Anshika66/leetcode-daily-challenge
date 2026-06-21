class Solution {
  public:
    int findKRotation(vector<int> &arr) {
       int low = 0;
       int high = arr.size()-1;
       int n = arr.size();
       
       int cnt = 0;
       while(low <= high){
           int guess = (low+high)/2;
           
           if(arr[guess] > arr[n-1]){
               cnt = cnt + (guess-low+1);
               low = guess+1;
           }else{
               high = guess-1;
           }
       }
       
       return cnt;
        
    }
};

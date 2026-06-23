class Solution {
  public:
    int maxi(vector<int> &arr){
        int low = INT_MIN;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            if(arr[i] > low){
                low = arr[i];
            }
        }
        return low;
    }
    bool fun(vector<int> &arr, int k , int guess){
        int n = arr.size();
        int boys = 1;
        int pages = 0;
        
        for(int i = 0;i<n;i++){
           
            if(pages + arr[i]<= guess ){
                pages = pages+arr[i];
            }else{
                boys++;
                pages=arr[i];
                
                if(boys> k){
                    return false ;
                }
            }
        }
        
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(n<k){
            return -1;
        }
        int low = maxi(arr);
        
        int high = 0;
        for(int i = 0;i<n ; i++){
            high+= arr[i];
        }
        int ans = 0;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(fun(arr, k, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return ans;
        
    }
};

class Solution {
public:
    int maxElement(vector<int>& bloomDay){
        int maxi = INT_MIN;
        int n = bloomDay.size();
        for(int i = 0;i<n ;i++){
            maxi = max(bloomDay[i] , maxi);
        }

        return maxi;
    }

    int minElement(vector<int>& bloomDay){
        int mini = INT_MAX;
        int n = bloomDay.size();
        for(int i = 0;i<n ;i++){
            mini = min(bloomDay[i] , mini);
        }

        return mini;
    }

    bool possible(vector<int>& bloomDay, int m, int k , int days){
        int cnt = 0;
        int no_bouq = 0;

        int n = bloomDay.size();

        for(int i = 0;i<n ;i++){
            if(bloomDay[i] <= days){
                cnt++;
            }
            else{
                no_bouq += (cnt/k);
                cnt = 0;
            }
        }

        no_bouq += (cnt/k);
        if(no_bouq >= m){
            return true;
        }
        else{
            return false ;
        } 
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int low = minElement(bloomDay);
        int high = maxElement(bloomDay);
        int ans = INT_MAX;

        if( (long long)m * k > n)  return -1;


        while(low<=high){
            int mid = (low+high)/2;

            if(possible(bloomDay , m , k , mid )== true ){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }


        return ans ;
    }
};

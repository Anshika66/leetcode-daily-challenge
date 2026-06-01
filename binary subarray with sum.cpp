class Solution {
public:
    int solve(vector<int>&A , int S , int n){
        int l = 0;
        int r = 0;
        int sum  = 0 ; 
        int count = 0 ; 

        while(r<n){
            if(S < 0 ) return 0;
            sum += A[r];
            while(sum > S){
                sum = sum - A[l];
                l++;
            }

            count += (r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        int ans = solve(A, S, n) - solve(A , S-1, n);
        return ans ;
        
    }
};

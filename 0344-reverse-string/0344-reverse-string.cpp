class Solution {
public:
    void fun(vector<char>&s , int low , int high , int n ){
        int len = high - low +1 ;
        if(len == 1 || len  == 0) return ;

        swap(s[low] , s[high]);
        return fun(s , low+1 , high-1 , n);
    }
    void reverseString(vector<char>& s) {
        int n = s.size();
        fun(s , 0 , n-1 , n);
    }
};
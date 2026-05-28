class Solution {
public:
    void solve(int n , int open , int close , string temp , vector<string>&ans){
        if(temp.length() == 2*n ){
            ans.push_back(temp);
            return ; 
        }
        if(open < n)
            solve( n , open +1 , close , temp +'(' , ans );
        if(close < open )
            solve(n , open , close + 1 , temp + ')' , ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans ; 
        string temp = "";
        int open = 0;
        int close = 0;
        solve( n ,0 , 0 ,  temp , ans );
        return ans;
        
    }
};

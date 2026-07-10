class Solution {
public:
    void solve(int n , int open , int close , string &tmp , vector<string>&ans){
       if(tmp.length() == 2*n){
        ans.push_back(tmp);
        return ;
       }

       //open 
       if(open < n){
        tmp.push_back('(');
        solve(n , open +1 , close , tmp , ans);
        tmp.pop_back();
       }

       //close
       if(close < open){
        tmp.push_back(')');
        solve(n , open , close+1 , tmp , ans);
        tmp.pop_back();
       }
    }
    vector<string> generateParenthesis(int n) {
        string tmp="" ;
        int close = 0;
        int open = 0;

        vector<string>ans;

        solve(n , 0 , 0 , tmp , ans);
        return ans ;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans ;
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        if(intervals.empty()){
            return ans ;
        }

          ans.push_back(intervals[0]); 

        for(int i = 1;i<n;i++){
            vector<int>&last = ans.back();
            if(last[1] >= intervals[i][0]){
                last[1] = max(last[1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans ; 
    }
};

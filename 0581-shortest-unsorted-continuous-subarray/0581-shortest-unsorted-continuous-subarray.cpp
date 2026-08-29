class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>copy;

        for(int i = 0 ;i < n ; i++){
            copy.push_back(nums[i]);
        }

        sort(copy.begin() , copy.end());

        int first = -1 ;
        int last = -1;

        for(int i = 0 ; i < n  ; i++){
            if(copy[i] != nums[i]){
                if(first == -1){
                    first = i;
                }
                last  = i;
            }
        }

        if(first == -1){
            return 0;
        }

        int len = last - first + 1;
        return len ; 
        
    }
};
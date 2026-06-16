class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n  = nums.size();
        int slow = 0;
        int fast = 0;
        while(true){
            slow = nums[slow] ;
            fast = nums[fast] ;
            fast = nums[fast];
            if(slow == fast){
                int temp = 0 ; 

                while(temp != slow){
                    temp = nums[temp];
                    slow = nums[slow];
                }
                return temp;
            }
        }
        return 0;
        
    }
};

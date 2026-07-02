class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int, vector<int> , greater<int>>pq;
        
        for(int i = 0;i< arr.size(); i++){
            pq.push(arr[i]);
        }
        
        while(k != 1){
            pq.pop();
            k--;
        }
        int small = pq.top();
        return small;
    }
};

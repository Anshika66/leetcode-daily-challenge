class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int> pq;

        for(auto &it : stones){
            pq.push(it);
        }

        while(!pq.empty()){
            if(pq.size() == 1){
                return pq.top();
            }
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x != y){
                pq.push(y-x);
            }
        }
        return 0;
        
    }
};
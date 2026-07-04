class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a,
                        const pair<int,int>& b) const {
            return a.first > b.first;   // Min Heap
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pair<int, int> , vector<pair<int, int>> , cmp > pq;
        unordered_map<int , int> f;
        for(int i = 0; i< n ; i++){
            f[nums[i]]++;
        }

        for(auto i : f){
            int element = i.first ; 
            int freq = i.second;

           pair<int , int> curr = {freq , element};

           if(pq.size() <k){
            pq.push(curr);
            continue;
           }

           if(curr.first < pq.top().first){
            continue;
           }else {
            pq.pop();
            pq.push(curr);
           }
        }

        vector<int> ans; 
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
class Solution {
    public:
    struct Compare {
        bool operator()(pair<int, int> a, pair<int, int> b) {

            
            if (a.second != b.second)
                return a.second < b.second;

            // If distances are equal, larger value should be on top
            return a.first < b.first;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

        for(auto it : arr){
            pair<int, int> curr  = {it, abs(it-x)};

            if(pq.size() < k){
                pq.push(curr);
            }else{
                if((curr.second < pq.top().second) ||( curr.second == pq.top().second && curr.first < pq.top().first)){
                    pq.pop();
                    pq.push(curr);
                }
            }
        }

        vector<int>ans ; 
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        sort(ans.begin(), ans.end());  

        return ans ; 
    }
};
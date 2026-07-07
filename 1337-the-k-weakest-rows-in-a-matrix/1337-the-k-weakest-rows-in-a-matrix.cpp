class Solution {
public:
    struct cmp  {
        bool operator()(pair<int, int> a, pair<int, int> b) {

 
            if (a.second != b.second)
                return a.second < b.second;

        
            return a.first < b.first;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, int>freq;
        for(int i = 0; i< m ; i++){
            freq[i] = 0;
            for(int j = 0; j< n;j++){
                if(mat[i][j] == 1){
                    freq[i] ++;
                }
            }
        }
        

        priority_queue<pair<int , int> , vector<pair<int , int>> , cmp>pq;

        for(auto it : freq){
            pair<int , int> curr = {it.first , it.second};

            if(pq.size() < k){
                pq.push(curr);
            }else{
                if((curr.second < pq.top().second) || (curr.second == pq.top().second && curr.first < pq.top().first)){
                    pq.pop();
                    pq.push(curr);
                }
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        reverse(ans.begin() , ans.end());
        return ans ;
        
    }
};
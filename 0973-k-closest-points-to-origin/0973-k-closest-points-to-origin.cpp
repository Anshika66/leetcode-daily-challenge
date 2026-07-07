class Solution {
public:
    struct Compare {
        bool operator()(pair<vector<int>, float> a, pair<vector<int>, float> b) {

            // Larger distance should be on top
            if (a.second != b.second)
                return a.second < b.second;
            return false;
        }
    };
    float distance(int x , int y){
        return sqrt(x*x + y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
 

        priority_queue<pair<vector<int>, float>,
                       vector<pair<vector<int>, float>>,
                       Compare> pq;

        for(auto it : points){
            pair<vector<int> , float> curr= {it , distance(it[0] , it[1])};

            if(pq.size() <k){
                pq.push(curr);
            }
            else{
                if(curr.second  < pq.top().second){
                    pq.pop();
                    pq.push(curr);
                }
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans ;
     
    }
};
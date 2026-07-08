class Solution {
public:
    struct cmp{
        bool operator()(const pair<int  , char>&a , const pair<int, char>&b)const{
            if(a.first != b.first){
                return a.first < b.first;
            }
            return a.second < b.second;
        }

    };
    string reorganizeString(string s) {
        int n = s.length();

        unordered_map<char , int> freq;
        for(int i = 0; i< n; i++){
            freq[s[i]]++;
        }

        priority_queue<pair<int , char> , vector<pair<int , char>> , cmp>pq;

        for(auto it:freq){
            pq.push({it.second , it.first});
        }

        string res = "";
        int seat = 0;

        while(!pq.empty()){
            pair<int , char> curr = pq.top();
            pq.pop();
            if(res.length()== 0 || res[seat-1] != curr.second){
                res.push_back(curr.second);
                seat++;
                curr.first--;
                if(curr.first > 0){
                    pq.push(curr);
                }
            }else{
                if(pq.empty()){
                    return "";
                }

                pair<int , char> p1 = pq.top();
                pq.pop();
                res.push_back(p1.second);
                seat++;
                p1.first--;
                if(p1.first > 0 ){
                    pq.push(p1);
                }

                pq.push(curr);

            }
        }

        return res;
        
    }
};
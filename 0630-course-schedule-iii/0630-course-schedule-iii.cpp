class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();

        sort(courses.begin(), courses.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });
        

        int totaltime = 0;
        priority_queue<int>pq;
    

        for(auto &course : courses){
            int duration = course[0];
            int lastday = course[1];

            totaltime += duration;
            pq.push(duration);
            if(totaltime > lastday){
                totaltime -= pq.top();
                pq.pop();
            }
        }

        return pq.size(); 
    }
};
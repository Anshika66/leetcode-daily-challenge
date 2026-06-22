class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.length();
        unordered_map<char,int>have;
        unordered_map<char,int>need;

        string req = "balloon";

        for(int i = 0; i< req.length();i++){
            need[req[i]]++;
        }

        for(int i = 0;i<n ; i++){
            have[text[i]]++;
        }

        int mini = INT_MAX;
        for(auto ch : need ){
            char c  = ch.first;
            int Noneed = ch.second;

            int Nohave = have[c];

            int ans = Nohave / Noneed;
            mini = min(mini , ans );
            
        }
        return mini;
    }
};
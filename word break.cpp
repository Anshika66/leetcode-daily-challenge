class Solution {
public:

    bool solve(int idx, string& s, vector<string>& dict) {

        if(idx == s.length()) {
            return true;
        }

        for(int l = 1; idx + l <= s.length(); l++) {

            string temp = s.substr(idx, l);

            if(find(dict.begin(), dict.end(), temp) != dict.end()) {

                if(solve(idx + l, s, dict)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        return solve(0, s, wordDict);
    }
};

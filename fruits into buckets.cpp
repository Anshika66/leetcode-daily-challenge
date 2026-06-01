class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        int maxlen = 0;
        int l = 0;
        int r = 0;
        int n = fruits.size();
        map<int , int>mapp;

        while(r<n){
            mapp[fruits[r]]++;

            if(mapp.size()> 2){
                mapp[fruits[l]]--;
                if(mapp[fruits[l]] == 0) mapp.erase(fruits[l]);
                l++;
            }

            if(mapp.size()<=2){
                int len = r-l+1;
                maxlen = max(maxlen , len);
            }

            r++;
        }

        return maxlen ;
    }
};

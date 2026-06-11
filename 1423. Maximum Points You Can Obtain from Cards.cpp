class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxsum = 0;
        int leftSum = 0;
        int rightSum = 0;
        int n = cardPoints.size();
        for(int i = 0; i< k ; i++){
            leftSum += cardPoints[i];
            maxsum = leftSum ;
        }
        int rightIndex = n-1;
        for(int i = k-1; i>=0 ; i--){
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[rightIndex];
            rightIndex --;
            maxsum = max(maxsum , leftSum + rightSum);
        }

        return maxsum ;
    }
};

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return 0;

        sort(nums.begin(), nums.end());

        int l = 0;
        int maxWindow = 1;

        for (int r = 0; r < n; r++) {
            while (l < r && nums[r] > (long long)nums[l] * k) {
                l++;
            }
            maxWindow = max(maxWindow, r - l + 1);
        }

        return n - maxWindow;
    }
};

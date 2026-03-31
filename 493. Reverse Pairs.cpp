class Solution {
public:
    int cnt = 0;

    void merge(vector<int>& vec, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> leftVec(n1), rightVec(n2);

        for (int i = 0; i < n1; i++)
            leftVec[i] = vec[left + i];
        for (int j = 0; j < n2; j++)
            rightVec[j] = vec[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (leftVec[i] <= rightVec[j]) {
                vec[k++] = leftVec[i++];
            } else {
                vec[k++] = rightVec[j++];
            }
        }

        while (i < n1) vec[k++] = leftVec[i++];
        while (j < n2) vec[k++] = rightVec[j++];
    }

    void countPairs(vector<int>& vec, int left, int mid, int right) {
        int j = mid + 1;

        for (int i = left; i <= mid; i++) {
            while (j <= right && vec[i] > 2LL * vec[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }
    }

    void mergeSort(vector<int>& vec, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        countPairs(vec, left, mid, right);   
        merge(vec, left, mid, right);
    }

    int reversePairs(vector<int>& nums) {
        cnt = 0;                     
        int n = nums.size();          

        mergeSort(nums, 0, n - 1);

        return cnt;
    }
};

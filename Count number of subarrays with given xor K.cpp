int solve(int* A, int n1, int B) {
    int xr = 0;
    map<int , int>mapp;
    mapp[xr]++;
    int cnt = 0;
    for(int i = 0; i < n1; i++){
        xr = xr^A[i];
        int x = xr^B;
        cnt += mapp[x];
    }

    return cnt;
}

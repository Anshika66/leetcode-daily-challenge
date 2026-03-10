class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];

    int solve(int zeroleft, int onesleft, bool lastWasOne, int limit) {

        if (zeroleft == 0 && onesleft == 0) {
            return 1;
        }

        if (t[zeroleft][onesleft][lastWasOne] != -1) {
            return t[zeroleft][onesleft][lastWasOne];
        }

        long long result = 0;

        if (lastWasOne) { // place zeros
            for (int len = 1; len <= min(limit, zeroleft); len++) {
                result = (result + solve(zeroleft - len, onesleft, false, limit)) % M;
            }
        } 
        else { // place ones
            for (int len = 1; len <= min(limit, onesleft); len++) {
                result = (result + solve(zeroleft, onesleft - len, true, limit)) % M;
            }
        }

        return t[zeroleft][onesleft][lastWasOne] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));

        int startWithOne = solve(zero, one, false, limit);
        int startWithZero = solve(zero, one, true, limit);

        return (startWithOne + startWithZero) % M;
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool ishigh = n & 1;
        n >>= 1;

        while (n) {
            ishigh = !ishigh;
            cout << n << " " << ishigh<< endl;

            cout << (n&1) << endl;
            if ((n & 1) != ishigh)
                return false;
            n >>= 1;
        }
        return true;
    }
};

int main() {
    Solution solu;
    cout << solu.hasAlternatingBits(8) << endl;

    return 0;
}